/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала протокола PS2
 * 
 *  Мигрировано из открытого доступа
 */

#include <Arduino.h>

class PS2
{
public:
    PS2(int, int);
    void write(byte data);
    byte read();
private:
    int _ps2clk,
        _ps2data;
    void golo(int);
    void gohi(int);
};