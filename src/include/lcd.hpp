/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала ЖК-дисплея
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

#include <Arduino.h>
#include <LiquidCrystal.h>

class Display
{
private:
    LiquidCrystal *lcd;
    byte displayWidth;
    byte displayHeigth;
public:
    Display(byte, byte);
    ~Display();
    void clear();
    void print(byte*, byte);
    void print(String);
    void move(byte, byte);
};