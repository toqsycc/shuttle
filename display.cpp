#include "lib/display.hpp"

Display::Display(uint8_t width, uint8_t heigth) :
    displayWidth(width),
    displayHeigth(heigth)
{
    lcd = new LiquidCrystal(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
    lcd->begin(displayWidth, displayHeigth);
}

void Display::print(uint8_t *array, uint8_t length)
{
    lcd->write(array, length);
}

void Display::print(String str)
{
    lcd->print(str);
}

void Display::move(uint8_t x, uint8_t y)
{
    if (x >= 0 && x < displayWidth && y >= 0 && y < displayHeigth)
        lcd->setCursor(x, y);
    else return;
}

void Display::clear()
{
    lcd->clear();
}