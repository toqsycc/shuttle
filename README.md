# Колёсный робот на базе Arduino
![Общий вид сборки](/cad/screenshot.png)
## История версий
- [x] v0.05 - **Текущая версия**  
Внесённые изменения:  
* Исправлена ширина релейного модуля и модуля драйвера;
* Увеличены отверстия под светодиодную ленту;
* Исправлено крепление батарейного отсека;
* Исправлена глубина посадки термореле и датчика температуры;
* Сделал шахту провода под батарейным блоком глубже.
- [ ] v0.04  
Внесённые изменения:
* Угол развала колёс уменьшен до -2.25 градусов;
* Клиренс увеличен на 2 мм;
* Увеличены диаметры отверстий под валы моторов и ключей на задней части рамы;
* Исправлены углы отклонения для RGB-ленты, подсвечивающей лонжероны;
* Исправлены отверстия под крепления лонжеронов;
* Увеличена дистанция между светодиодами ленты;
* Увеличена высота держателя моторов на 2 мм;
* Изменено положение батарейного блока и драйвера двигателей;
* Добавлены посадочные позиции для термореле и температурного датчика, а также шахты для их проводов.
- [ ] v0.03  
Внесённые изменения:
* Уменьшен размер задней рамы в соответствии с обновлёнными пропорциями.
- [ ] v 0.02  
Внесённые изменения:
* Добавлены отверстия под RGB-ленты и крепления под драйвер двигателей и реле.
- [ ] v 0.01 - **Начало работы**  
Внесённые изменения:
* Сформирована модель задней рамы в соответствии с пропорциями.
## Общая информация
Разработка в процессе
## Назначение
Робот является демонстрационной моделью для автономной езды по полигону в двух базовых режимах: *вдоль чёрной линии* или *между двух препятствий*.  
Референсом внешнего вида является суперкар Lamborghini Diablo 1991.  
Помимо автономного режима предумотрено управление через Bluetooth. С помощью встроенного ЖК-дисплея формата 1602 происходит вывод информации **на русском языке**.  
Прошивка написана на языке программирования C++ с использованием ООП.
## Аппаратные компоненты
- Arduino Mega 2560 R3
- DBH-12V Dual DC Motor Drive
- 4x TT Motors
- 5x TCRT5000 IR Line Sensor
- 2x HC-SR04 US Distance Meter
- PCA9685 PWM Servo Controller
- MG996 Servo
- AHT10 Temperature Sensor
- MPU6050 Accelerometer
- WINSTAR WH1602 LCD
- HC-05 Bluetooth Module
- HW-504 Joystick
- Relay Module 5V 10A
- TXS0108 Logic Converter
- SX1308 DC-DC Converter
## Особенности
Разработка в процессе