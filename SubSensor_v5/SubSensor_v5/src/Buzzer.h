#ifndef Buzzer_H
#define Buccer_H
#include <Arduino.h>

class Buzzer
{
private:
    int LastBeep = 0;
    int LastStable = 0;
    int Count = 0;
    byte Buzzer_IO;
    byte Now_Output = LOW;

public:
    bool OnOff = false;
    void SetPin(byte IO_Buzzer)
    {
        pinMode(IO_Buzzer, OUTPUT);
        Buzzer_IO = IO_Buzzer;
    }
    void Output(int Duration)
    {
        // Duration = 0, always low
        // Duration = 1, always high
        // other, high when Count % LastBeep = Duration;
        if (Now_Output == HIGH && (Duration != 1 || !OnOff))
        {
            digitalWrite(Buzzer_IO, LOW);
            Now_Output = LOW;
        }
        else if (OnOff && Count - LastBeep >= Duration && Duration != 0)
        {
            digitalWrite(Buzzer_IO, HIGH);
            Now_Output = HIGH;
            LastBeep = Count;
        }
        Count++;
    }
    void Angle_Output(float Angle)
    {
        float diff = abs(Angle - 90);
        if (diff < 0.2)
        {
            if (LastStable == 0)
                LastStable = millis();
            Output((millis() - LastStable < 30000));
            return;
        }
        LastStable = 0;
        if (diff < 1)
        {
            Output(2);
        }
        else if (diff < 2)
        {
            Output(4);
        }
        else if (diff < 5)
        {
            Output(8);
        }
        else if (diff < 10)
        {
            Output(16);
        }
        else
        {
            Output(0);
        }
    }
};

#endif