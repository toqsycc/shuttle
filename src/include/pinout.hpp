/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Распиновка материнской платы
 * 
 *  Разработчик:    toqsycc
 *                  26.09.22
 */

// DONE: Записать пины управления двигателем, АЦП батарей и двигателей, исправить TRIG и ECHO на действительные значения
#define EXHAUST_LIGHT_B     2   // Цветные ШИМ-каналы шины выхлопа
#define EXHAUST_LIGHT_G     3   //
#define EXHAUST_LIGHT_R     4   //
#define REAR_R_LIGHT_B      8   // Цветные ШИМ-каналы шины правой задней фары
#define REAR_R_LIGHT_G      9   //
#define REAR_R_LIGHT_R      10  //
#define REAR_L_LIGHT_B      11  // Цветные ШИМ-каналы шины левой задней фары
#define REAR_L_LIGHT_G      12  //
#define REAR_L_LIGHT_R      13  //
#define SERVO_CONTROL_PIN   22  // Пин управления сервоприводом
#define RELAY_CONTROL_PIN   23  // Пин управления реле
#define STRIP_DATA_RIGHT    50  // Пин данных правой светодиодной ленты
#define STRIP_DATA_LEFT     51  // Пин данных левой светодиодной ленты
#define PS2_CLOCK_PIN       53  // Пин тактирования тачпада
#define PS2_DATA_PIN        52  // Пин данных тачпада
#define SONIC_L_TRIG        40  // Пин сигнала левого УЗ-датчика
#define SONIC_L_ECHO        42  // Пин отклика левого УЗ-датчика
#define SONIC_R_TRIG        41  // Пин сигнала правого УЗ-датчика
#define SONIC_R_ECHO        43  // Пин отклика правого УЗ-датчика
#define ENGINE_A_EN1        49  // Пин EN1-A модуля управления двигателями
#define ENGINE_A_EN2        47  // Пин EN2-A модуля управления двигателями
#define ENGINE_A_PWM        45  // Пин PWM-A модуля управления двигателями
#define ENGINE_B_EN1        48  // Пин EN1-B модуля управления двигателями
#define ENGINE_B_EN2        46  // Пин EN2-B модуля управления двигателями
#define ENGINE_B_PWM        44  // Пин PWM-B модуля управления двигателями
#define BATTERY_ENG         A0  // Пин статуса аккумулятора нагрузки
#define BATTERY_SELF        A1  // Пин статуса аккумулятора электроники
#define ENGINE_A_FDB        A2  // Пин FDB-A модуля управления двигателями
#define ENGINE_B_FDB        A3  // Пин FDB-B модуля управления двигателями
#define DISPLAY_BKL         37  // Состояние подсветки дисплея
#define DISPLAY_RS          38  // Register Select
#define DISPLAY_EN          39  // Enable
#define DISPLAY_D0          26  // Шина данных дисплея
#define DISPLAY_D1          27  //
#define DISPLAY_D2          28  //
#define DISPLAY_D3          29  //
#define DISPLAY_D4          30  //
#define DISPLAY_D5          31  //
#define DISPLAY_D6          32  //
#define DISPLAY_D7          33  //
#define INFRARED_O1         16  // Шина данных инфракрасного датчика
#define INFRARED_O2         17  //
#define INFRARED_O3         34  //
#define INFRARED_O4         35  //
#define INFRARED_O5         36  //