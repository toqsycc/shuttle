#include "lib/shuttle.hpp"
#include "lib/messages.hpp"

Shuttle::Shuttle()
{
    dsp = new Display(16, 2);
    dsp->print(mode, 6);
}