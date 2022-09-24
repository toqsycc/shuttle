/*
 *  Проект беспилотного устройства на базе Arduino Mega 2560
 *  Заголовок функционала встроенного ультразвукового датчика дистанции
 * 
 *  Разработчик:    toqsycc
 *                  22.09.22
 */

class UltrasonicSensor
{
private:
    const byte                  triggerPin,
                                echoPin;
    unsigned long               distance,
                                __triggeredTimestamp,
                                __receivedTimestamp;
    void initiateTrigger();
    void awaitForEcho();
    void onEchoEvent();
public:
    UltrasonicSensor(const byte, const byte);
    inline unsigned long getDistance(){ return distance; }
};