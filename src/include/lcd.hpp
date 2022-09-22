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
    uint8_t displayWidth;
    uint8_t displayHeigth;
public:
    Display(uint8_t width, uint8_t heigth);
    ~Display();
    void clear();
    void print(uint8_t *array, uint8_t length);
    void print(String str);
    void move(uint8_t x, uint8_t y);
};