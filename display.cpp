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