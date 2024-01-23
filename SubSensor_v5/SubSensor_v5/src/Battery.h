#ifndef Battery_H
#define Battery_H

#include <Arduino.h>
class Battery
{
private:
    byte p;

public:
    int Percent = 0;
    void SetPin(byte Pin)
    {
        p = Pin;
        pinMode(p, INPUT);
    }
    void Update()
    {
        int TimeStamp = millis();
        int Count = 0;
        int Sum = 0;
        while (millis() - TimeStamp < 100)
        {
            int B = analogRead(p);
            if (B != 0)
            {
                Sum += B;
                Count++;
            }
            delay(1);
        }
        if (Count > 1)
        {
            Percent = (((float)Sum / Count + 1.0 - 2220.0)  * 100.0/ 300.0 + 0.5);
            Percent = min(max(Percent,0),100);
        }
            
    }
};

#endif