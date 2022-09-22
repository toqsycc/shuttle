/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала встроенного датчика температуры
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

#include <Arduino.h>
#include <Wire.h>
#include <Thinary_AHT10.h>

class TemperatureSensor
{
private:
    byte                        pin;
    byte                        *values;
    byte *convertToByte();
public:
    TemperatureSensor(byte);
    byte *getSensorData();
};