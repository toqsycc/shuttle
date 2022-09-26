/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала модуля управления двигателями
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

#include <Arduino.h>

class EngineDriver
{
private:
    byte                        __en1_a,
                                __en2_a,
                                __pwm_a,
                                __fdb_a,
                                __en1_b,
                                __en2_b,
                                __pwm_b,
                                __fdb_b;
public:
    EngineDriver();
    void moveForward(byte);
    void moveBackward(byte);
    void halt();
};