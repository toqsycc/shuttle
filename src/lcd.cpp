/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Основной код функционала ЖК-дисплея
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

#include <lcd.hpp>
#include <pinout.hpp>

Display::Display(byte width, byte heigth) :
    displayWidth(width),
    displayHeigth(heigth)
{
    lcd = new LiquidCrystal(
        DISPLAY_RS, DISPLAY_EN, 
        DISPLAY_D0, DISPLAY_D1, DISPLAY_D2, DISPLAY_D3, 
        DISPLAY_D4, DISPLAY_D5, DISPLAY_D6, DISPLAY_D7);
    lcd->begin(displayWidth, displayHeigth);
    lcd->setCursor(0x00, 0x00);
}

void Display::clear()
{
    lcd->clear();
}

void Display::move(byte x, byte y)
{
    lcd->setCursor(x, y);
}

void Display::print(String string)
{
    lcd->print(string.c_str());
}

void Display::print(byte *string, byte length)
{
    for (byte i(0); i < length; i++)
        lcd->print(string[i]);
}