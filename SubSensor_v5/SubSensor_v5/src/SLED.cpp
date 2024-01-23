#include "SLED.h"

#define LED_PIN 40
#define LED_COUNT 13
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void SLED::Initialize()
{
    strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
    strip.show();  // Turn OFF all pixels ASAP
    AdjuestBrightness(0);
    isBegin = true;
}

void SLED::Update()
{
    if (Block)
        return;
    IMU_Color();
    strip.show();
}

void SLED::AdjuestBrightness(int Add)
{
    Brightness += Add;
    Brightness %= 6;
    int B = pow(2, Brightness) * 8 - (Brightness == 5);
    strip.setBrightness(B);
}

void SLED::IMU_Color()
{
    int k = (*Angle - 90) / step + 20;
    for (int i = 0; i < (strip.numPixels() + 1) / 2; i++)
    {
        uint32_t Color;
        if (k + i < 8)
            Color = strip.Color(255, 0, 0);
        else if (k + i == 8)
            Color = strip.Color(224, 32, 0);
        else if (k + i == 9)
            Color = strip.Color(192, 64, 0);
        else if (k + i == 10)
            Color = strip.Color(160, 96, 0);
        else if (k + i < 17)
            Color = strip.Color(128, 128, 0);
        else if (k + i == 17)
            Color = strip.Color(96, 160, 0);
        else if (k + i == 18)
            Color = strip.Color(64, 192, 0);
        else if (k + i == 19)
            Color = strip.Color(32, 244, 0);
        else if (k + i < 28)
            Color = strip.Color(0, 255, 0);
        else if (k + i == 28)
            Color = strip.Color(32, 244, 0);
        else if (k + i == 29)
            Color = strip.Color(64, 192, 0);
        else if (k + i == 30)
            Color = strip.Color(96, 160, 0);
        else if (k + i < 37)
            Color = strip.Color(128, 128, 0);
        else if (k + i == 37)
            Color = strip.Color(160, 96, 0);
        else if (k + i == 38)
            Color = strip.Color(192, 64, 0);
        else if (k + i == 39)
            Color = strip.Color(224, 32, 0);
        else
            Color = strip.Color(255, 0, 0);
        strip.setPixelColor(i, Color);
        strip.setPixelColor(strip.numPixels() - 1 - i, Color);
    }
}

void SLED::LowPower()
{
    if (!isBegin)
        Initialize();
    strip.clear();
    strip.setBrightness(255);
    for (int i = 4; i < (strip.numPixels() + 1) / 2; i++)
    {
        uint32_t Color = strip.Color(pow(4, i - 3), 0, 0);
        strip.setPixelColor(i, Color);
        strip.setPixelColor(strip.numPixels() - 1 - i, Color);
    }
    strip.show();
    Block = true;
}

void SLED::AutoOffReminder()
{
    Block = true;
    if (!isBegin)
        Initialize();
    strip.clear();
    strip.setBrightness(128);
    for (int i = 4; i < (strip.numPixels() + 1) / 2; i++)
    {
        uint32_t Color = strip.Color(0, pow(4, i - 3) - 1, pow(4, i - 3) - 1);
        strip.setPixelColor(i, Color);
        strip.setPixelColor(strip.numPixels() - 1 - i, Color);
    }
    strip.show();
}

void SLED::Clear()
{
    strip.clear();
    strip.show();
    Block = true;
}
