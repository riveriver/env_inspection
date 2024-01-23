#include "OLED.h"
#include "OLED_XBM.h"
#define OLED1309

#ifdef OLED1309
U8G2_SSD1309_128X64_NONAME0_F_4W_SW_SPI u8g2(U8G2_R0, 48, 35, 36, 37, OLED_RST);
#else
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
#endif

void OLED::SetPin(byte IO_VCC, byte IO_VDD)
{
    if (VCC == 0)
        VCC = IO_VCC;
    else
        Debug.println("[OLED] VCC already set.");
    if (VDD == 0)
        VDD = IO_VDD;
    else
        Debug.println("[OLED] VDD already set.");
}

void OLED::Begin()
{
    if (!isU8G2Begin)
    {
        if (VCC == 0 || VDD == 0)
        {
            Debug.println("[OLED] Pin not set.");
            return;
        }
        // Vdd On
        // pinMode(VDD, INPUT_PULLUP);
        pinMode(OLED_RST, OUTPUT);
        digitalWrite(OLED_RST, LOW);
        delay(1);
        digitalWrite(OLED_RST, HIGH);
        delay(1);
        pinMode(VCC, OUTPUT);
        digitalWrite(VCC, HIGH);
        pinMode(1, OUTPUT);
        digitalWrite(1, HIGH);
        delay(100);
        //*
        Wire.beginTransmission(60);
        byte error = Wire.endTransmission();
        if (error == 0)
            I2C_Add = 0x3C;
        else if (error == 4)
            Serial.print("Unknown error at address 0x3C");
        else
        {
            Wire.beginTransmission(61);
            error = Wire.endTransmission();
            if (error == 0)
                I2C_Add = 0x3D;
            else if (error == 4)
                Serial.print("Unknown error at address 0x3D");
        }

        if (I2C_Add == 0x00)
        {
            u8g2.setI2CAddress(0x3D * 2);
            Debug.println("[OLED] OLED Address Not Found. Try to begin u8g2 anyway.");
        }
        else
        {
            u8g2.setI2CAddress(I2C_Add * 2);
            Debug.println("[OLED] OLED begin, Address = 0x" + String(I2C_Add, HEX));
        }
        while (millis() < 1000)
            ;
        //*/
        u8g2.setPowerSave(0);
        u8g2.begin();
        isU8G2Begin = true;
        u8g2.clear();
        u8g2.sendBuffer();
    }
}

void OLED::Initialize()
{
    Begin();
    u8g2.enableUTF8Print();
    u8g2.setFlipMode(0);
    u8g2.setFont(Default_Font);
    u8g2.setFontDirection(0);
    u8g2.setFontMode(1);
    u8g2.setDrawColor(1);
    u8g2.clearBuffer();
    char S[19] = "Wonder Construct";
    u8g2.drawStr(64 - u8g2.getStrWidth(S) / 2, 30, S);
    char S1[17] = "Sensor V4.0";
    u8g2.drawStr(64 - u8g2.getStrWidth(S1) / 2, 50, S1);
    u8g2.sendBuffer();
    BlockTime = millis() + 3000;
}

void OLED::Clear()
{
    Begin();
    u8g2.clear();
    u8g2.initDisplay();
}

void OLED::ShowLowPower()
{
    Begin();
    u8g2.setFont(u8g2_font_open_iconic_check_2x_t);
    u8g2.setFontDirection(0);
    u8g2.setFontMode(1);
    u8g2.clearBuffer();
    u8g2.drawRBox(30, 17, 68, 35, 7);
    u8g2.drawRBox(89, 27, 15, 15, 7);
    u8g2.setDrawColor(0);
    u8g2.drawRBox(33, 20, 62, 29, 5);
    u8g2.setDrawColor(1);
    u8g2.drawGlyph(57, 42, 0x0044);
    u8g2.sendBuffer();
}

void OLED::TurnOff()
{
    Begin();
    u8g2.clear();
    u8g2.initDisplay();
    u8g2.setPowerSave(1);
    delay(1);
    pinMode(VCC, INPUT);
    delay(100);
    pinMode(VDD, INPUT);
    delay(1);
    pinMode(OLED_RST, INPUT);
}

void OLED::Block(String BlockInfo)
{
    Begin();
    if (BlockInfo == "")
    {
        BlockTime = millis();
        return;
    }
    else
    {
        BlockTime = millis() + 3000;
        u8g2.clearBuffer();
        int Rotation = (imu->Gravity % 3 == 2) ? imu->GravityPrevious : imu->Gravity;
        switch (Rotation)
        {
        case 0:
            u8g2.setDisplayRotation(U8G2_R1);
            break;
        case 3:
            u8g2.setDisplayRotation(U8G2_R3);
            break;
        case 4:
            u8g2.setDisplayRotation(U8G2_R2);
            break;
        default:
            u8g2.setDisplayRotation(U8G2_R0);
            break;
        }
        u8g2.setFont(Default_Font);
        const unsigned int Mx = u8g2.getDisplayWidth();
        const unsigned int My = u8g2.getDisplayHeight();
        const unsigned int a = u8g2.getAscent() - u8g2.getDescent();
        int s[10] = {0};
        int s_now = BlockInfo.indexOf(" ");
        int s_next, w;
        int i = 0;
        if (s_now == -1)
        {
            s_now = BlockInfo.length();
            i++;
            s[i] = s_now + 1;
        }
        while (s_now < BlockInfo.length())
        {
            w = u8g2.getStrWidth(BlockInfo.substring(s[i], s_now).c_str());
            s_next = -1;
            while (w <= Mx)
            {
                s_now += s_next + 1;
                if (s_now > BlockInfo.length())
                    break;
                s_next = BlockInfo.substring(s_now + 1).indexOf(" ");
                if (s_next == -1)
                    s_next = BlockInfo.substring(s_now + 1).length();
                w = u8g2.getStrWidth(BlockInfo.substring(s[i], s_now + s_next + 1).c_str());
            }
            i++;
            s[i] = s_now + 1;
            s_next = BlockInfo.substring(s[i]).indexOf(" ");
            if (s_next == -1 && s_now < BlockInfo.length())
            {
                i++;
                s[i] = BlockInfo.length() + 1;
                break;
            }
            s_now += s_next + 1;
        }
        unsigned int sh = a * 1.25;
        unsigned int h = sh * (i - 1) + a;
        while (h > My)
        {
            sh--;
            h = sh * (i - 1) + a;
        }
        unsigned int y = (My - h) / 2 + u8g2.getAscent();
        for (int j = 0; j < i; j++)
        {
            w = u8g2.getStrWidth(BlockInfo.substring(s[j], s[j + 1] - 1).c_str());
            u8g2.drawStr((Mx - w) / 2, y, BlockInfo.substring(s[j], s[j + 1] - 1).c_str());
            y += sh;
        }
        u8g2.sendBuffer();
    }
}

void OLED::Update()
{
    // FlashCount++;
    if (millis() < BlockTime)
        return;
    // int t = millis();
    u8g2.clearBuffer();
    //  u8g2.setFont(u8g2_font_helvR10_tr);
    //  u8g2.drawStr(0, 30, String(millis()).c_str());
    //  u8g2.drawStr(0, 60, ClockShow->DateTimeStamp().c_str());
    // Serial.print(millis() - t);
    // Serial.print(", ");
    // t = millis();
    Main();
    
    // u8g2.setDrawColor(2);
    // u8g2.drawBox(0, 0, 130, 70);
    u8g2.sendBuffer();
    // Serial.println(millis() - t);
}

void OLED::Main()
{
    char Angle[8];
    dtostrf(imu->getXFilt(), 7, 2, Angle);
    u8g2.setFont(u8g2_font_logisoso42_tn);
    for (int i = 0; i < 4; i++)
    {
        char S[2];
        S[0] = Angle[i];
        int D = 0;
        u8g2.drawGlyph(27 * i - 17 + (i == 0) * 11, 64, Angle[i]);
    }
    u8g2.setFont(u8g2_font_logisoso34_tn);
    u8g2.drawGlyph(88, 64, '.');
    u8g2.setFont(u8g2_font_logisoso20_tn);
    for (int i = 5; i < 7; i++)
    {
        char S[2];
        S[0] = Angle[i];
        int D = 0;
        u8g2.drawGlyph(25 + 15 * i, 64, Angle[i]);
    }
    u8g2.setFont(u8g2_font_siji_t_6x10);
    if (*Buzz)
        u8g2.drawGlyph(13, 8, 0xe04e);
    else
        u8g2.drawGlyph(13, 8, 0xe04f);
    u8g2.drawXBM(4, 0, 7, 8, Bulb_7x8);
    u8g2.drawFrame(0, 1, 3, 7);
    u8g2.drawVLine(1, 7 - *Brightness, *Brightness);
    Battery(108, 0, 20, 8, 3);
    u8g2.setFont(u8g2_font_helvR08_tr);
    u8g2.drawStr(51, 8, ClockShow->TimeStamp("Now","").substring(0,2).c_str());
    u8g2.drawStr(67, 8, ClockShow->TimeStamp("Now","").substring(2,4).c_str());
    if (ClockShow->now.second() % 2 == 0)
        u8g2.drawStr(63, 7, ":");
}

void OLED::Battery(int x, int y, int w, int h, int b)
{

    int B = (h > 20 && w > 20) ? 2 : 1;
    int d = (h < 8 || w < 8) ? 0 : B;

    if (h > w)
    {
        u8g2.drawBox(x + (w + 1) / 4, y, w - (w + 1) / 4 * 2, b);
        for (int i = 0; i < B; i++)
        {
            u8g2.drawFrame(x + i, y + b + i, w - 2 * i, h - b - 2 * i);
        }
        int LF = min(max(*Bat * (h - b - 2 * B - 2 * d) / 100, 0), (h - b - 2 * B - 2 * d));
        u8g2.drawBox(x + B + d, y + h - LF - B - d, w - 2 * B - 2 * d, LF);
    }
    else
    {
        u8g2.drawBox(x + w - b, y + (h + 1) / 4, b, h - (h + 1) / 4 * 2);
        for (int i = 0; i < B; i++)
        {
            u8g2.drawFrame(x + i, y + i, w - b - 2 * i, h - 2 * i);
        }
        int LF = min(max(*Bat * (w - b - 2 * B - 2 * d) / 100, 0), (w - b - 2 * B - 2 * d));
        u8g2.drawBox(x + B + d, y + B + d, LF, h - 2 * B - 2 * d);
    }
}

void OLED::Clock()
{
    if (ClockShow->RtcLostPower)
    {
        u8g2.setFont(u8g2_font_open_iconic_embedded_2x_t);
        u8g2.drawGlyph(0, 41, 0x0047);
    }
    String NowSet = (ClockShow->Cursor == -1) ? "Now" : "Set";
    u8g2.setFont(Default_Font);
    u8g2.drawStr(9, 13, ClockShow->DateStamp(NowSet, "WWW").c_str());
    String GMT = "GMT+8";
    int w = u8g2.getStrWidth(GMT.c_str());
    u8g2.drawStr(118 - w, 13, GMT.c_str());
    if (ClockShow->Cursor != 0 || Flash(3, 6))
    {
        u8g2.drawStr(9, 64, ClockShow->DateStamp(NowSet, "YYYY").c_str());
    }
    if (ClockShow->Cursor != 1 || Flash(3, 6))
    {
        char S[4];
        strcpy(S, ClockShow->DateStamp(NowSet, "MMM").c_str());
        int w = u8g2.getStrWidth(S);
        u8g2.drawStr(72 - w / 2, 64, S);
    }
    if (ClockShow->Cursor != 2 || Flash(3, 6))
    {
        u8g2.drawStr(103, 64, ClockShow->DateStamp(NowSet, "DD").c_str());
    }
    u8g2.setFont(u8g2_font_helvR24_tn);
    String Time = ClockShow->TimeStamp(NowSet, "");
    if (ClockShow->Cursor != 3 || Flash(3, 6))
    {
        u8g2.drawGlyph(17, 45, Time.charAt(0));
        u8g2.drawGlyph(37, 45, Time.charAt(1));
    }
    if (ClockShow->Cursor != 4 || Flash(3, 6))
    {
        u8g2.drawGlyph(74, 45, Time.charAt(2));
        u8g2.drawGlyph(94, 45, Time.charAt(3));
    }
    if (ClockShow->Cursor != -1 || atoi(Time.substring(5).c_str()) % 2 != 1)
    {
        u8g2.drawGlyph(58, 42, 0x003a);
    }
}

void OLED::EasyBlock(String BlockInfo)
{
    BlockTime = millis() + 3000;
    u8g2.clearBuffer();
    String str = BlockInfo.substring(0, 1);
    String RemainString = BlockInfo.substring(1);

    int i = 0;
    int l = 0;
    while (l != -1)
    {
        l = RemainString.indexOf(str);
        RemainString = RemainString.substring(l + 1);
        i++;
    }
    int h = (u8g2.getAscent() - u8g2.getDescent()) * 1.5;
    int y = (64 - i * h) / 2 + u8g2.getAscent();
    RemainString = BlockInfo.substring(1);
    for (int j = 0; j < i; j++)
    {
        int l = RemainString.indexOf(str);
        u8g2.drawStr(0, y + h * j, ("/" + RemainString.substring(0, l)).c_str());
        RemainString = RemainString.substring(l + 1);
    }
    u8g2.sendBuffer();
}

void OLED::Save()
{
    u8g2.setFont(MSpace_Font);
    u8g2.setDrawColor(2);
    u8g2.drawStr(0, 11, "SD");
    u8g2.drawStr(14, 11, ":");
    u8g2.drawStr(21, 11, (pSD->Show.endsWith(".csv")) ? "Ready" : pSD->Show.c_str());
    u8g2.drawBox(0, 14, 128, 2);
    u8g2.drawBox(0, 18 + 16 * pSD->Cursor, 128, 14);
    int w;
    w = u8g2.getStrWidth("Back");
    u8g2.drawStr(64 - w / 2, 30, "Back");
    if (pSD->Show == "Function OFF")
    {
        w = u8g2.getStrWidth("Turn ON");
        u8g2.drawStr(64 - w / 2, 46, "Turn ON");
    }
    else
    {
        w = u8g2.getStrWidth("Turn OFF");
        u8g2.drawStr(64 - w / 2, 46, "Turn OFF");
    }
    if (pSD->Show.endsWith(".csv"))
    {
        w = u8g2.getStrWidth("File Name");
        u8g2.drawStr(64 - w / 2, 62, "File Name");
    }
}

void OLED::YesNo(bool isH, bool Select)
{
    u8g2.setFont(MSpace_Font);
    u8g2.setDrawColor(2);
    int w;
    if (isH)
    {
        u8g2.drawBox(43, 28 + 20 * Select, 42, 14);
        u8g2.drawFrame(41, 26, 46, 18);
        u8g2.drawFrame(41, 46, 46, 18);
        w = u8g2.getStrWidth("No");
        u8g2.drawStr(64 - w / 2, 40, "No");
        w = u8g2.getStrWidth("Yes");
        u8g2.drawStr(64 - w / 2, 60, "Yes");
    }
    else
    {
        u8g2.drawBox(2 + 33 * Select, 112, 26, 14);
        u8g2.drawFrame(0, 110, 30, 18);
        u8g2.drawFrame(33, 110, 30, 18);
        w = u8g2.getStrWidth("No");
        u8g2.drawStr(15 - w / 2, 124, "No");
        w = u8g2.getStrWidth("Yes");
        u8g2.drawStr(48 - w / 2, 124, "Yes");
    }
}

void OLED::Cal_M()
{
    u8g2.setFont(MSpace_Font);
    u8g2.setDrawColor(2);
    int w;
    u8g2.drawStr(0, 11, "Calibration");
    u8g2.drawBox(0, 13, 128, 2);
    u8g2.drawBox(0, 17 + 16 * (imu->Cursor - imu->CursorStart), 128, 14);
    char Cal_Mode[4][16] = {"Back", "Calibrate", "Clear", "Exp Cal"};
    for (int i = 0; i < 3; i++)
    {
        w = u8g2.getStrWidth(Cal_Mode[i + imu->CursorStart]);
        u8g2.drawStr(64 - w / 2, 29 + i * 16, Cal_Mode[i + imu->CursorStart]);
    }
}

void OLED::Cal()
{
    u8g2.setFont(MSpace_Font);
    u8g2.setDrawColor(2);
    if (imu->CalibrateCheck == 0)
    {
        String Question;
        if (imu->Cursor == 1)
            Question = "Ready to Calibrate?";
        else if (imu->Cursor == 2)
            Question = "Sure to Clear Data?";
        else if (imu->Cursor == 3)
        {
            Question = "g = " + String(imu->Gravity);
            if (!(imu->Gravity > 2))
                Question += (imu->FullCalComplete[imu->Gravity]) ? ", Complete." : ", Ready?";
        }
        if (Rotation % 3 != 0)
        {
            int w = 0;
            for (int i = 0; i < Question.length(); i++)
            {
                u8g2.drawGlyph(w, 13, Question.charAt(i));
                w += (Question[i] == ' ') ? 5 : 7;
            }
        }
        else
        {
            int w = 0;
            int l1 = Question.substring(7).indexOf(" ") + 8;
            u8g2.drawStr(0, 15, Question.substring(0, l1 - 1).c_str());
            for (int i = 0; i < Question.substring(l1).length() - (imu->Cursor != 3); i++)
            {
                char a = Question.substring(l1).charAt(i);
                w -= (a == 'l') ? 2 : 0;
                u8g2.drawGlyph(w, 35, a);
                w += (a == ' ' || a == 'l') ? 5 : 7;
            }
            if (imu->Cursor != 3)
                u8g2.drawGlyph(0, 55, Question.charAt(Question.length() - 1));
        }

        if (imu->Cursor == 3 && (imu->Gravity > 2 || imu->FullCalComplete[imu->Gravity]))
        {
            u8g2.drawBox(u8g2.getDisplayWidth() / 2 - 21, u8g2.getDisplayHeight() - 16, 42, 14);
            u8g2.drawFrame(u8g2.getDisplayWidth() / 2 - 23, u8g2.getDisplayHeight() - 18, 46, 18);
            u8g2.drawStr((u8g2.getDisplayWidth() - u8g2.getStrWidth("Back")) / 2, u8g2.getDisplayHeight() - 4, "Back");
        }
        else
            YesNo((Rotation % 3 != 0), imu->YesNo);
    }
    else if (imu->CalibrateCheck == 1)
    {
        for (int i = 1; i < 3; i++)
        {
            u8g2.drawGlyph(0, 20 * i - 5, 120 + ((imu->Gravity + i) % 3));
            u8g2.drawGlyph(7, 20 * i - 5, '=');
            char A[8];
            dtostrf(imu->Angle[(imu->Gravity + i) % 3], 7, 3, A);
            u8g2.drawStr(15, 20 * i - 5, A);
        }
        if (Rotation % 3 != 0)
        {
            u8g2.drawFrame(12, 50, 104, 14);
            u8g2.drawBox(14, 52, imu->CalibrateCount * 4, 10);
        }
        else
        {
            u8g2.drawFrame(5, 100, 54, 14);
            u8g2.drawBox(7, 102, imu->CalibrateCount * 2, 10);
        }
    }
}

bool OLED::Flash(int Due, int Period)
{
    return (FlashCount % Period < Due);
}
