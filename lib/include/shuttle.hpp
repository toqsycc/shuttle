#include <Arduino.h>
#include "display.hpp"
#include "temperature.hpp"

class Shuttle
{
private:
    Display *dsp;
    byte shuttleInit();
    uint16_t batteryChargeA;    // Напряжение аккумулятора моторов
    uint16_t batteryChargeB;    // Напряжение аккумулятора логики
public:
    Shuttle();
    ~Shuttle();
};