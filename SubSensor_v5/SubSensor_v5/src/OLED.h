#ifndef OLED_H
#define OLED_H
#include <U8g2lib.h>
#include <Wire.h>
#include "IMU42688.h"
#include "RealTimeClock.h"
#include "BLE.h"
#include "SerialDebug.h"

#define H 1
#define V 0

#ifndef TestVersion
#define TestVersion false
#endif

#ifndef OLED_RST
#define OLED_RST 11
#endif

class OLED
{
private:
    byte VCC = 0;
    byte VDD = 0;
    int Count = 0;
    int Rotation = -1;
    void Begin();
    bool isU8G2Begin = false;
    uint8_t I2C_Add = 0x00;
    void Main();
    void Battery(int x, int y, int w, int h, int b);
    void Clock();
    void Cal();
    void YesNo(bool isH, bool Select);
    void Cal_M();
    void Save();
    bool Flash(int Due, int Period);
    int FlashCount;

    const uint8_t *Default_Font = u8g2_font_helvB10_tr;
    const uint8_t *Describe_Font = u8g2_font_helvB08_tr;
    const uint8_t *MSpace_Font = u8g2_font_7x14B_tr;

public:
    int *Bat;
    RealTimeClock *ClockShow;
    IMU42688 *imu;
    BLE *pBLE;
    bool *SDState;
    bool *fSave;
    bool *Buzz;
    SDCard *pSD;
    byte State = 0;
    byte Page = 0;
    byte MenuCursor = 0;
    byte *Brightness;
    int BlockTime = 0;
    void SetPin(byte IO_VCC, byte IO_VDD);
    void Initialize();
    void Clear();
    void TurnOff();
    void ShowLowPower();
    void Update();
    void Block(String BlockInfo);
    void EasyBlock(String BlockInfo);
};

#endif