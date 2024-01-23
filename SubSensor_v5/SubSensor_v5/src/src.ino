// PCB V7
// Close / Open component individually
#include <Arduino.h>
#include "SerialDebug.h"

SerialDebug D;
extern SerialDebug Debug = D;
const gpio_num_t Pin_Button_Wakeup = GPIO_NUM_0;
const byte Pin_RTC_EN = 1;
const byte Pin_Button0 = 0;
const byte Pin_Button2 = 6;
const byte Pin_Button1 = 7;
const byte Pin_I2C_SDA = 8; // Default
const byte Pin_I2C_SCL = 9; // Default
const byte Pin_EN = 10;
const byte Pin_SD_EN = 5;
const byte IO_OLED_VDD = 2;
const byte IO_OLED_VCC = 4;
const byte IO_OLED_RST = 11;
const byte Pin_SD_MOSI = 12;
const byte Pin_SD_MISO = 13;
const byte Pin_SD_SCK = 14;
const byte Pin_SD_CS = 15;
const byte Pin_Battery = 17; // ratio = /2
const byte Pin_Batt_Charge = 20;
const byte Pin_Buzzer = 18;
const byte Pin_OLED_MISO = 35;
const byte Pin_OLED_CS = 36;
const byte Pin_OLED_DC = 37;
const byte Pin_OLED_SCLK = 48;
const byte Pin_IMU_RX = 38;
const byte Pin_IMU_TX = 39;
const byte Pin_LED = 40;

/*
LED Setting
LED 0 :
  R-L - Bat Low Power (1)
  Y-L - IMU Not Warm Up (2)
  B-F - IMU Waiting for Stable (2)
  B-L - IMU Collecting Data (2)
  G-L - IMU Collect Data Done (2)
  M-L - RTC Lost Power (0)
  M-F - RTC Set Time Success (3)
  W-L - IO-0 Press (4)
  W-F - RFID Find New (5)
LED 1 :
  R-F - Any Other Error (0)
  G-F - File Save Success / Create New File (1)
  Y-F - No SD (1)
LED 0 + 1 :
  G-F - Working
*/

#define OLED_RST IO_OLED_RST
#define TestVersion false

#include "SDCard.h"
#include "RealTimeClock.h"
RealTimeClock Clock;
#include "SLED.h"
#include "OLED.h"
#include "BLE.h"
#include "OnOff.h"
#include "IMU42688.h"
#include "Battery.h"
#include "Buzzer.h"

TaskHandle_t *T_FAST;
TaskHandle_t *T_LOOP;
TaskHandle_t *T_SEND;
TaskHandle_t *T_SAVE;
TaskHandle_t *T_BUFF;
TaskHandle_t *T_SLOW;

BLE ble;
IMU42688 imu;
OLED oled;
OnOff Swich;
SDCard sdCard;
Battery Bat;
SLED led;
Buzzer Buz;

int MainLoopDelay = 125;
int FastLoopDelay = 50;
int LastEdit = 0;
bool fHaveSD = false;
bool fSave = false;
String Msg = "";

static void FAST(void *pvParameter)
{
  TickType_t xLastWakeTime;
  BaseType_t xWasDelayed;
  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    xWasDelayed = xTaskDelayUntil(&xLastWakeTime, FastLoopDelay);
    if (!xWasDelayed && millis() > 10000)
      Debug.println("[Warning] Task FAST Time Out.");
    imu.Update();
  }
}

static void MAIN(void *pvParameter)
{
  TickType_t xLastWakeTime;
  BaseType_t xWasDelayed;
  xLastWakeTime = xTaskGetTickCount();
  int T = millis();
  for (;;)
  {
    xWasDelayed = xTaskDelayUntil(&xLastWakeTime, MainLoopDelay);
    if (!xWasDelayed & millis() > 10000)
      Debug.println("[Warning] Task MAIN Time Out.");
    
    Swich.Off_Clock_Check();
    ButtonUpdate();
    // I2C device update
    Clock.update();
    oled.Update();
    led.Update();
    Buz.Angle_Output(imu.Angle[0]);
  }
}

static void SLOW(void *pvParameter)
{
  vTaskDelay(1000);
  for (;;)
  {
    Bat.Update();
    vTaskDelay(10000);
  }
}

static void Send(void *pvPArameter)
{
  TickType_t xLastWakeTime;
  BaseType_t xWasDelayed;
  xLastWakeTime = xTaskGetTickCount();
  ble.Initialize(LastEdit);
  for (;;)
  {
    xWasDelayed = xTaskDelayUntil(&xLastWakeTime, 250);
    if (!xWasDelayed && millis() > 60000)
      Debug.println("[Warning] Task Send Time Out.");
    ble.Send(imu);
  }
}

static void Save(void *pvParameter)
{
  sdCard.SetPin(Pin_SD_SCK, Pin_SD_MISO, Pin_SD_MOSI, Pin_SD_CS, Pin_SD_EN);
  vTaskDelay(4000);
  sdCard.Swich(1);
  TickType_t xLastWakeTime;
  BaseType_t xWasDelayed;
  xLastWakeTime = xTaskGetTickCount();
  bool fHaveSD_pre = fHaveSD;
  bool isSDSave = sdCard.Err_SD_begin_Failed;
  for (;;)
  {
    xWasDelayed = xTaskDelayUntil(&xLastWakeTime, 10000);
    if (!xWasDelayed)
      Debug.println("[Warning] Task Save Time Out.");
    // Check SD State and save Debug String every Loop
    // Create and Save Data to file if fSave = true;
    fHaveSD_pre = fHaveSD;
    isSDSave = sdCard.Save("/" + ble.MyAddress + "/" + Clock.DateStamp("", 2), Msg);
    fHaveSD = (isSDSave == sdCard.SDOK || isSDSave == sdCard.Err_File_Write_Failed);
    if (fHaveSD && !fHaveSD_pre) // Check the file when the sd card first detected.
    {
      String Info = sdCard.Read("/Setting.txt");
      imu.ExpertMode = (Info.indexOf("Full_Cal_Password=123456789") != -1);
    }
    else if (!fHaveSD && fHaveSD_pre)
    {
      imu.ExpertMode = false;
      imu.Cursor = 0;
      imu.CursorStart = 0;
    }
  }
}

static void Buff(void *pvParameter)
{
  TickType_t xLastWakeTime;
  BaseType_t xWasDelayed;
  xLastWakeTime = xTaskGetTickCount();
  for (;;)
  {
    xWasDelayed = xTaskDelayUntil(&xLastWakeTime, 2000);
    if (!xWasDelayed && millis() > 10000)
      Debug.println("[Warning] Task Buff Time Out.");
    if (fHaveSD)
    {
      if (imu.ErrorCode != imu.Err_IMU_Not_Warm_Up && imu.ErrorCode < imu.Err_IMU_Cope_Failed + 10)
      {
        Msg += Clock.DateTimeStamp() + ",";
        Msg += String(imu.Angle[0], 3) + ",";
        Msg += String(imu.Angle[1], 3) + ",";
        Msg += String(imu.Angle[2], 3) + ",";
        Msg += String(imu.SensorTemperature, 2) + "\n";
      }
    }
  }
}

bool ButPress[3] = {false};

void ButtonChange0()
{
  ButPress[0] = true;
}

void ButtonChange1()
{
  ButPress[1] = true;
}

void ButtonChange2()
{
  ButPress[2] = true;
}

void ButtonUpdate()
{
  if (millis() - LastEdit < MainLoopDelay * 2 || millis() < oled.BlockTime)
    memset(ButPress, false, sizeof(ButPress));
  if (ButPress[0] || ButPress[1] || ButPress[2])
    LastEdit = millis();
  else if (oled.Page != 0 && millis() - LastEdit > 10000 && !TestVersion)
  {
    oled.Page = 0;
  }
  if(ButPress[0])
  {
    led.AdjuestBrightness(5);
  }
  if(ButPress[1])
  {
    Buz.OnOff = !Buz.OnOff;
  }
  if (ButPress[2])
  {
    led.AdjuestBrightness(1);
  }
  memset(ButPress, false, sizeof(ButPress));
}

void setup()
{
  oled.SetPin(IO_OLED_VCC, IO_OLED_VDD);
  Bat.SetPin(Pin_Battery);
  Swich.On(Pin_Button_Wakeup, Bat, oled, led, Pin_EN);
  if (Swich.TimerWakeUp)
    return;
  if (TestVersion)
    Debug.Setup(sdCard);
  led.Initialize();
  oled.Initialize();
  Clock.Initialize(MainLoopDelay);
  delay(1000);
  imu.Initialize(Pin_IMU_RX, Pin_IMU_TX);
  Buz.SetPin(Pin_Buzzer);
  Debug.SetRTC(&Clock);
  Debug.printOnTop("-------------------------ESP_Start-------------------------");
  Debug.println("[Battery] Battery " + String(Bat.Percent) + " %");
  // Swich.pSD = &sdCard;
  Swich.LastTriggure = &LastEdit;
  Swich.isBLEConnect = &ble.isConnect;
  led.Angle = &imu.Angle[0];

  oled.ClockShow = &Clock;
  oled.Bat = &Bat.Percent;
  oled.imu = &imu;
  oled.SDState = &fHaveSD;
  oled.fSave = &fSave;
  oled.pSD = &sdCard;
  oled.pBLE = &ble;
  oled.Brightness = &led.Brightness;
  oled.Buzz = &Buz.OnOff;

  pinMode(21,INPUT);
  
  while (!digitalRead(Pin_Button0))
    delay(1);
  xTaskCreatePinnedToCore(FAST, "Fast", 8192, NULL, 2, T_FAST, 1);
  xTaskCreatePinnedToCore(SLOW, "Slow", 2048, NULL, 0, T_SLOW, 0);
  xTaskCreatePinnedToCore(Send, "Send", 16384, NULL, 1, T_SEND, 0);
  xTaskCreatePinnedToCore(Save, "Save", 8192, NULL, 2, T_SAVE, 0);
  xTaskCreatePinnedToCore(Buff, "Buff", 4096, NULL, 1, T_BUFF, 0);
  xTaskCreatePinnedToCore(MAIN, "Main", 16384, NULL, 3, T_LOOP, 1);
  delay(100);
  attachInterrupt(digitalPinToInterrupt(Pin_Button2), ButtonChange2, FALLING);
  attachInterrupt(digitalPinToInterrupt(Pin_Button1), ButtonChange1, FALLING);
  attachInterrupt(digitalPinToInterrupt(Pin_Button0), ButtonChange0, FALLING);
  Serial.println("Setup Done");
}

void loop()
{
  // put your main code here, to run repeatedly:
}