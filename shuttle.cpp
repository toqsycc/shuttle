#include "lib/shuttle.hpp"
#include "lib/messages.hpp"

#include <MPU6050.h>

Shuttle::Shuttle()
{
    // Инициализация дисплея:
    dsp = new Display(16, 2);
    dsp->print(mode, 6);
    dsp->move(7, 0);
    dsp->print(mdInit, 4);

    // Измерение напряжения аккумуляторов:
    
    // Измерение температуры аккумуляторного отсека:
    AHT10Class aht;
    Wire.begin();
    aht.begin(eAHT10Address_Low);
    dsp->move(0, 1);
    dsp->print(String(aht.GetTemperature()));

    MPU6050 mpu;
    mpu.initialize();
    dsp->move(7, 1);
    dsp->print(String(mpu.getRotationY()));

    dsp->move(7, 0);
    dsp->print(mdAuto, 4);
    for(;;)
    {
        dsp->move(0, 1);
        dsp->print(String(aht.GetTemperature()));
        dsp->move(7, 1);
        dsp->print(String(mpu.getRotationZ()));
        delay(150);
    }
}