class TCRT5000
{
private:
    byte *pins;         // Contains data pin numbers for each input
    byte values;        // Variable for compressed sensor values (booleans to byte)

    byte getSensorsData();
    byte convertToByte(byte *array);
public:
    TCRT5000();
    ~TCRT5000();
};