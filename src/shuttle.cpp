/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Исходный код основного класса устройства - Shuttle
 * 
 *  Разработчик:    toqsycc
 *                  21.09.22
 */

#include <shuttle.hpp>

Shuttle::Shuttle()
{
    //  Инициализация периферии
    enginesPower = new Relay(RELAY_CONTROL_PIN, true);
    steeringWheel = new Servo();

    //  Инициализация датчиков
    sonicLeft = new UltrasonicSensor(SONIC_L_TRIG, SONIC_L_ECHO);
    sonicRight = new UltrasonicSensor(SONIC_R_TRIG, SONIC_R_ECHO);

    Serial1.begin(BLUETOOTH_BAUD);

    steeringWheel->attach(SERVO_CONTROL_PIN);
    steeringWheel->write(90);

    //  Основной цикл работы устройства
    for(;;)
    {
        //  Обработка данных, полученных с пульта
        if (Serial1.available() == 4)
        {
            lastCommand = millis();
            memcpy(prevCommandBuffer, commandBuffer, 4);

            commandBuffer[Direction] = Serial1.read();
            commandBuffer[Speed] = Serial1.read();
            commandBuffer[Angle] = Serial1.read();
            commandBuffer[Peripheral] = Serial1.read();

            if ((commandBuffer[Angle] <= 0xB4) && 
                ((commandBuffer[Direction] <= 0xF5) && (commandBuffer[Direction] >= 0xF1)))
            {
                //  Обработка команд движения
                if (commandBuffer[Direction] <= 0xF3)
                {
                    switch (commandBuffer[Direction])
                    {
                    case 0xF1:  //  Движение вперёд
                        if (prevCommandBuffer[Direction] != 0xF1)
                            engines->moveForward(commandBuffer[Speed]);
                        break;
                    case 0xF2:  //  Движение назад
                        if (prevCommandBuffer[Direction] != 0xF2)
                            engines->moveBackward(commandBuffer[Speed]);
                        break;
                    default:    //  Остановка моторов
                        if (prevCommandBuffer[Direction] != 0xF3)
                        {
                            engines->halt();
                            rearLeftColor = new HSL(Colors::Red, 1.0, 0.5);
                            rearRightColor = new HSL(Colors::Red, 1.0, 0.5);
                            rearLeftLight->switchColor(rearLeftColor->getColorArrayRGB());
                            rearRightLight->switchColor(rearRightColor->getColorArrayRGB());
                        }
                        break;
                    }

                    if (prevCommandBuffer[Speed] != commandBuffer[Speed])
                        engines->setSpeed(commandBuffer[Speed]);
                    if (prevCommandBuffer[Angle] != commandBuffer[Angle])
                        steeringWheel->write(commandBuffer[Angle]);
                }
                //  Обработка команды полной остановки
                else if (commandBuffer[Direction] == 0xF5)
                {
                    if (prevCommandBuffer[Direction] != 0xF5)
                    {
                        engines->halt();
                        exhaustColor = new HSL();
                        rearLeftColor = new HSL(Colors::Red, 1.0, 0.25);
                        rearRightColor = new HSL(Colors::Red, 1.0, 0.25);
                    }
                }
                else    //  Обработка кода 0xF4
                {

                }
                //  Обработка команд управления периферией
                if (prevCommandBuffer[Peripheral] != commandBuffer[Peripheral])
                {
                    
                }
            }
        }

        //  
        else
        {
            lastState = millis();
            if ((lastState - lastCommand) > 400l)
            {
                /*
                 *  Отключаем устройство по причине таймаута связи и переводим в режим бездействия
                 */
                enginesPower->disable();
            }

        }
    }
}