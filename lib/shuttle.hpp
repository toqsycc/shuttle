#include <Arduino.h>
#include "display.hpp"

class Shuttle
{
private:
    Display *dsp;
    byte shuttleInit();
public:
    Shuttle();
    ~Shuttle();
};