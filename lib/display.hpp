#include <Arduino.h>
#include <LiquidCrystal.h>

#define LCD_RS 8
#define LCD_EN 9
#define LCD_D4 14
#define LCD_D5 15
#define LCD_D6 16
#define LCD_D7 17

class Display
{
private:
    LiquidCrystal *lcd;
    uint8_t displayWidth;
    uint8_t displayHeigth;
public:
    Display(uint8_t width, uint8_t heigth);
    ~Display();
    void print(uint8_t *array, uint8_t length);
};