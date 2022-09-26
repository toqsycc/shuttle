/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Основной код функционала модуля управления двигателями
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

#include <pinout.hpp>
#include <dbh.hpp>

EngineDriver::EngineDriver() :
    __en1_a(ENGINE_A_EN1),
    __en2_a(ENGINE_A_EN2),
    __pwm_a(ENGINE_A_PWM),
    __en1_b(ENGINE_B_EN1),
    __en2_b(ENGINE_B_EN2),
    __pwm_b(ENGINE_B_PWM)
{
    pinMode(__en1_a, OUTPUT);
    pinMode(__en2_a, OUTPUT);
    pinMode(__pwm_a, OUTPUT);
    pinMode(__en1_b, OUTPUT);
    pinMode(__en2_b, OUTPUT);
    pinMode(__pwm_b, OUTPUT);
}