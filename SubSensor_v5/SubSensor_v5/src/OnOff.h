#ifndef LongPressSwich_H
#define LongPressSwich_H

#include <Arduino.h>
#include "OLED.h"
#include "SerialDebug.h"
#include "OLED.h"
#include "SLED.h"
#include "Battery.h"
#include "esp_bt.h"
RTC_DATA_ATTR int bootCount = -1;

class OnOff
{
private:
    int LEDFlashCount = 0;
    int OffClock = 0;
    byte ButPin;
    Battery *pBattery;
    OLED *pOLED;
    SLED *pLED;
    byte ENPin;

public:
    int *LastTriggure;
    bool *isBLEConnect;
    bool TimerWakeUp = false;
    void On(gpio_num_t WakeUpPin, Battery &Bat, OLED &oled, SLED &led, byte EN)
    {
        pLED = &led;
        pBattery = &Bat;
        pBattery->Update();
        // Wake Up Mode
        if (esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_TIMER)
        {
            if (pBattery->Percent <= 0)
            {
                pLED->LowPower();
            }
            else
            {
                pLED->AutoOffReminder();
            }

            TimerWakeUp = true;
            return;
        }
        pinMode(EN, OUTPUT);
        digitalWrite(EN, HIGH);
        ENPin = EN;
        bootCount++;
        // Begine from sleeping
        // Setting
        Serial.setRxBufferSize(256);
        Serial.begin(115200);
        Serial.println("Start");
        Wire.begin();
        Wire.setClock(400000);
        pOLED = &oled;
        ButPin = WakeUpPin;
        pinMode(ButPin, INPUT);
        // Battary Test
        if (pBattery->Percent <= 0)
        {
            pLED->LowPower();
            pOLED->Clear();
            delay(10000);
            pOLED->TurnOff();
            esp_deep_sleep_start();
        }
    }

    void Off_Clock_Check()
    {
        bool TimeOffSleep = ((millis() - *LastTriggure > 5 * 60 * 1000) && millis() > 10 * 60 * 1000 && !*isBLEConnect);
        bool LowPowerOff = (pBattery->Percent < 0);

        if (!TimeOffSleep && !LowPowerOff)
        {
            return;
        }
        if (LowPowerOff)
        {
            pOLED->Block("Low Battery");
            pLED->LowPower();
            Debug.println("Low Battery Sleep");
        }
        else if (TimeOffSleep)
        {
            pOLED->Block("Auto Sleep");
            pLED->AutoOffReminder();
            Debug.println("Auto Sleep");
        }
        if (TimeOffSleep || LowPowerOff)
        {
            Debug.println("[Battery] Battery " + String(pBattery->Percent) + " %");
            int ForShow = millis();
            while (millis() - ForShow < 2500)
            {
                if (TimeOffSleep)
                {
                    if (digitalRead(ButPin) == 0)
                    {
                        *LastTriggure = millis();
                        return;
                    }
                    delay(10);
                }
            }
            pOLED->TurnOff();
            Wire.end();
            SPI.end();
            Serial.end();
            digitalWrite(ENPin, LOW);
            esp_bt_controller_disable();
            esp_deep_sleep_start();
        }
    }
};
#endif