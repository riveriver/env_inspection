#ifndef SLED_H
#define SLED_H
#include <Adafruit_NeoPixel.h>

class SLED
{
public:
    void Initialize();
    void Update();
    void LowPower();
    void AutoOffReminder();
    void Clear();
    void AdjuestBrightness(int Add);
    byte Brightness = 2;
    byte mode = 0;
    float *Angle;
    int k_all = 0;
    float step = 0.2;
private :
    bool Block = false;
    void IMU_Color();
    bool isBegin = false;
};

#endif