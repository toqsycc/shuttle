#include "lib/shuttle.hpp"

int main()
{
    init();
    analogWrite(7, 128);
    
    Shuttle *shuttle = new Shuttle();
    
    return 0;
}