/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала LED лент, мигрировано с проекта @toqsycc/arduino-tower
 * 
 *  Разработчик:    EuthanasiaTrip
 *                  17.02.22
 */

#include <Arduino.h>
#include <FastLED.h>

class LEDStrip
{
private:
	CRGB leds[8];
	CRGB leds_side1[4];
public:
	LEDStrip();
	void activate();
	void showRed(double hue, int dVal = 100);
	void showBlue(double hue, int dVal = 100);
	void showSide(double hueStart = 0.0, double hueEnd = 0.8, int dVal = 100);
	void turnOff(int dVal = 100);
};