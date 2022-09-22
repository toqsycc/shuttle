#include <rgbd.hpp>

RGBDiode::~RGBDiode()
{
  memset(this, NULL, sizeof(*this));
}

RGBDiode::RGBDiode(byte* pins)
{
  this->channels = new byte[3]{0x00};
  this->pinsInfo = pins;
  this->InitializeBus();
}

RGBDiode::RGBDiode(byte *pins, byte *clr)
{
  this->pinsInfo = pins;
  this->channels = clr;
  this->InitializeBus();
}

void RGBDiode::SwitchColor(byte *clr)
{
  this->channels = clr;
  for (byte i(0); i < 3; i++)
  {
    analogWrite(this->pinsInfo[i], ~this->channels[i]);
  }
}

inline void RGBDiode::InitializeBus()
{
    for (byte i(0); i < 3; i++)
    {
        analogWrite(this->pinsInfo[i], ~this->channels[i]);
    }
}