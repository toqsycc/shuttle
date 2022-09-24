/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала четырёхвыводных RGB светодиодов
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

#include <Arduino.h>

class RGBDiode
{
private:
    byte                        *channels;
    byte                        *pinsInfo;
    inline void InitializeBus();
public:
    RGBDiode(byte*);
    RGBDiode(byte*, byte*);
    ~RGBDiode();
    void switchColor(byte*);
};