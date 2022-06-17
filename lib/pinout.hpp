/*

    Распиновка микроконтроллера Arduino Mega 2560

*/

#define BATTERY_A       A0  // Аккумулятор питания моторов
#define BATTERY_B       A1  // Аккумулятор питания логики
#define CURRENT_L       A2  // Обратная связь по току, левые моторы
#define CURRENT_R       A3  // Обратная связь по току, правые моторы
#define STICK_X         A4  // Ось абсцисс джойстика
#define STICK_Y         A5  // Ось ординат джойстика
#define STICK_BTN       A6  // Нажатие на джойстик
#define LCD_RS          8   // Контакт RS ЖК-дисплея
#define LCD_EN          9   // Контакт EN ЖК-дисплея
#define LCD_D4          14  // Контакт D4 ЖК-дисплея
#define LCD_D5          15  // Контакт D5 ЖК-дисплея
#define LCD_D6          16  // Контакт D6 ЖК-дисплея
#define LCD_D7          17  // Контакт D7 ЖК-дисплея
#define IR_INPUT_1      2   // Цифровой вход ИК-датчика 1
#define IR_INPUT_2      3   // Цифровой вход ИК-датчика 2
#define IR_INPUT_3      4   // Цифровой вход ИК-датчика 3
#define IR_INPUT_4      5   // Цифровой вход ИК-датчика 4
#define IR_INPUT_5      6   // Цифровой вход ИК-датчика 5
#define DBH_IN1_A       22  // Управление двигателями A
#define DBH_IN1_B       23  // Управление двигателями B
#define DBH_IN2_A       24  // Управление двигателями A
#define DBH_IN2_B       25  // Управление двигателями B
#define DBH_EN_A        26  // Включение двигателей A
#define DBH_EN_B        27  // Включение двигателей B
#define I2C_SCL         21  // Порт SCL
#define I2C_SDA         20  // Порт SDA
#define I2C_INT         

// Адреса I2C устройств
#define TEMP_ADDR       0x38        // Может быть 0x39
#define ACCL_ADDR       0x68        // Может быть 0x69
#define SCTL_ADDR       0x40