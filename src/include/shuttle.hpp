/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок основного класса устройства - Shuttle
 * 
 *  Разработчик:    toqsycc
 *                  21.09.22
 */

#include <Arduino.h>
#include <HardwareSerial.h>

//  Секция логики устройства
#include <rgbd.hpp>             // Управление RGB светодиодами
#include <led.hpp>              // Управление RGB лентами
#include <lcd.hpp>              // Управление ЖК-дисплеем
#include <ps2.hpp>              // Управление PS2 тачпадом
#include <dbh.hpp>              // Управление драйвером двигателей
#include <accelerometer.hpp>    // Управление датчиком-акселерометром
#include <temperature.hpp>      // Управление датчиком температуры
#include <ultrasonic.hpp>       // Управление ультразвуковыми датчиками дистанции
#include <infrared.hpp>         // Управление инфракрасными датчиками линии
#include <colors.hpp>           // Библиотека HSL оттенков
#include <ru_strings.hpp>       // Библиотека строк на кириллице

//  Секция драйверов устройства
#include <Servo.h>

//  Секция внешних констант
#define BLUETOOTH_BAUD      115200
#define SERVO_FORWARD_ANGLE 90

// TODO: Записать пины управления двигателем, АЦП батарей и двигателей, исправить TRIG и ECHO на действительные значения
#define EXHAUST_LIGHT_B     2   // Цветные ШИМ-каналы шины выхлопа
#define EXHAUST_LIGHT_G     3   //
#define EXHAUST_LIGHT_R     4   //
#define REAR_R_LIGHT_B      8   // Цветные ШИМ-каналы шины правой задней фары
#define REAR_R_LIGHT_G      9   //
#define REAR_R_LIGHT_R      10  //
#define REAR_L_LIGHT_B      11  // Цветные ШИМ-каналы шины левой задней фары
#define REAR_L_LIGHT_G      12  //
#define REAR_L_LIGHT_R      13  //
#define SERVO_CONTROL_PIN   22  // Пин управления сервоприводом
#define RELAY_CONTROL_PIN   23  // Пин управления реле
#define STRIP_DATA_RIGHT    50  // Пин данных правой светодиодной ленты
#define STRIP_DATA_LEFT     51  // Пин данных левой светодиодной ленты
#define PS2_CLOCK_PIN       53  // Пин тактирования тачпада
#define PS2_DATA_PIN        52  // Пин данных тачпада
#define SONIC_L_TRIG        88  // Пин сигнала левого УЗ-датчика
#define SONIC_L_ECHO        89  // Пин отклика левого УЗ-датчика
#define SONIC_R_TRIG        98  // Пин сигнала правого УЗ-датчика
#define SONIC_R_ECHO        99  // Пин отклика правого УЗ-датчика

//  Секция вспомогательных классов логики и периферии
class Relay
{
private:
    byte                    relayPin;
    byte                    currentState;
    byte                    hasInvertedLogic;
    const byte              __disable = 0x00;
    const byte              __enable = 0xFF;
public:
    Relay(byte pin, byte hasInvertedLogic = 0x00) :
        relayPin(pin),
        currentState(__disable)
    {
        pinMode(relayPin, OUTPUT);
        if (hasInvertedLogic)       digitalWrite(relayPin, ~__disable);
        else                        digitalWrite(relayPin, __disable);
    }
    inline byte isOpened() { return currentState; }
    inline void enable()
    {
        if (currentState == __enable) return;
        else
        {
            currentState = __enable;
            if (hasInvertedLogic)   digitalWrite(relayPin, ~__enable);
            else                    digitalWrite(relayPin, __enable);
        }
    }
    inline void disable()
    {
        if (currentState == __disable) return;
        else
        {
            currentState = __disable;
            if (hasInvertedLogic)   digitalWrite(relayPin, ~__disable);
            else                    digitalWrite(relayPin, __disable);
        }
    }
};

class HSL
{
private:
    byte                    *colorArray;
    inline double convertHueToRGB(double p, double q, double t)
    {
        if (t < 0.0)                t += 1.0;
        if (t > 1.0)                t -= 1.0;
        if (t > (1.0 / 6.0))
            return p + (q - p) * 6.0 * t;
        if (t < 0.5)
            return q;
        if (t < (2.0 / 3.0))
            return p + (q - p) * (2.0 / 3.0 - t) * 6.0;
        return p;
    }
public:
    HSL(double h = 0.0, double s = 0.0, double l = 0.0)
    {
        colorArray = new byte[3]{ 0x00 };

        if (s <= 0.0)               for (byte i(0); i < 3; i++)
            colorArray[i] = static_cast<byte>(255.0 * l);
    }
    ~HSL()
    {
        delete[] colorArray;
    }
    inline byte *getColorArrayRGB() { return colorArray; }
};

enum CommandBufferIndexes
{
    Direction,
    Speed,
    Angle,
    Peripheral
};

enum PeripheralIndexes
{
    FrontLight,
    BackLight,
    Horn,
    ButtonA,
    ButtonB,
    ButtonC,
    ButtonD,
    ButtonE
};

//  Класс Shuttle - основной класс устройства
class Shuttle
{
private:
    //  Объекты периферийных классов устройства
    EngineDriver            *engines;
    PS2                     *ps2;
    RGBDiode                *exhaustLight,
                            *rearLeftLight,
                            *rearRightLight;
    LEDStrip                *longeroneLeftLight,
                            *longeroneRightLight;
    Display                 *screen;
    TemperatureSensor       *temperature;
    AccelerometerSensor     *accelerometer;
    InfraredSensor          *infrared;
    UltrasonicSensor        *sonicLeft,
                            *sonicRight;
    Servo                   *steeringWheel;
    Relay                   *enginesPower;
    HSL                     *exhaustColor,
                            *rearLeftColor,
                            *rearRightColor;

    //  Данные для передачи пульту управления
    byte                    *feedbackData;

    //  Буферы полученных с пульта данных
    byte                    *commandBuffer;
    byte                    *prevCommandBuffer;

    //  Константы для вычислений
    const double            voltageStep = 0.004;

    //  Счетчики
    unsigned long           lastState = 2000l;
    unsigned long           lastReading = 0l;
    unsigned long           lastCommand = 0l;

    //  Флаги состояний устройства
    byte                    currentState;

    //  Константы флагов состояний устройства
    const byte              __deviceLaunching = 0x00;
    const byte              __deviceConfiguring = 0x01;
    const byte              __deviceAutomoving = 0x02;
    const byte              __deviceDriving = 0x04;
    const byte              __deviceHardfault = 0xFF;

    //  Показатели АЦП
    unsigned short          engineBatteryValue,
                            deviceBatteryValue,
                            engineFeedbackLeft,
                            engineFeedbackRight;
public:
    Shuttle();

    void ConfigurationMode();   // Режим конфигурации устройства
    void AutonomousMode();      // Режим автономной езды
    void DrivingMode();         // Режим езды с пультом
    void IdleMode();            // Режим бездействия

    void HardfaultHandler();    // Режим защиты устройства от критических ошибок
};