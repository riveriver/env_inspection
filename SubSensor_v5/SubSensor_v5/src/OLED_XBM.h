#ifndef OLED_XBM_H
#define OLED_XBM_H

static unsigned char Waiting13x17[] = {
    0xFF, 0x1F, 0x02, 0x08, 0x02, 0x08, 0x52, 0x09, 0xA4, 0x04, 0x48, 0x02,
    0x10, 0x01, 0xA0, 0x00, 0x40, 0x00, 0xA0, 0x00, 0x10, 0x01, 0x48, 0x02,
    0x04, 0x04, 0xA2, 0x08, 0x52, 0x09, 0xAA, 0x0A, 0xFF, 0x1F};
static unsigned char Up10x3[] = {0x30, 0x00, 0xFC, 0x00, 0xFF, 0x03};
static unsigned char Down10x3[] = {0xFF, 0x03, 0xFC, 0x00, 0x30, 0x00};
static unsigned char Left3x10[] = {0x04, 0x04, 0x06, 0x06, 0x07, 0x07, 0x06, 0x06, 0x04, 0x04};
static unsigned char Right3x10[] = {0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x03, 0x03, 0x01, 0x01};

static unsigned char Fire24x24[] = {
    0x00, 0x06, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x38, 0x00, 0x00, 0x78, 0x00,
    0x00, 0xF8, 0x00, 0x00, 0xFC, 0x01, 0x00, 0xFE, 0x03, 0x00, 0xFF, 0x03,
    0x80, 0xFF, 0x07, 0xC0, 0xFF, 0x07, 0xC4, 0xFF, 0x27, 0xE6, 0xFF, 0x73,
    0xE7, 0xEF, 0xFB, 0xEF, 0xF7, 0xFF, 0xFF, 0xF3, 0xFF, 0xFF, 0xE3, 0xFF,
    0xFF, 0xC3, 0x7F, 0x9F, 0x83, 0x7D, 0x3F, 0x01, 0x7E, 0x3E, 0x00, 0x3E,
    0x7C, 0x00, 0x1F, 0xFC, 0x00, 0x1F, 0xF0, 0x83, 0x0F, 0xC0, 0xE7, 0x03};
static unsigned char Ready24x24[] = {
    0x80, 0x81, 0x01, 0xE0, 0x81, 0x07, 0xF0, 0xC3, 0x0F, 0xF0, 0xFF, 0x0F,
    0xE0, 0xFF, 0x07, 0xE0, 0xC3, 0x07, 0xF0, 0x00, 0x0F, 0x70, 0x00, 0x0E,
    0x38, 0x00, 0x1C, 0x3F, 0x80, 0xFC, 0x1F, 0xC0, 0xF9, 0x1F, 0xE0, 0xF8,
    0x1F, 0x71, 0xF8, 0x9F, 0x3B, 0xF8, 0x3F, 0x1F, 0xFC, 0x38, 0x0E, 0x1C,
    0x70, 0x04, 0x0E, 0xF0, 0x00, 0x0F, 0xE0, 0xC3, 0x07, 0xE0, 0xFF, 0x07,
    0xF0, 0xFF, 0x0F, 0xF0, 0xC3, 0x0F, 0xE0, 0x81, 0x07, 0x80, 0x81, 0x01};
static unsigned char Done24x24[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x78,
    0x00, 0x00, 0xFC, 0x00, 0x00, 0xFE, 0x00, 0x00, 0x7F, 0x00, 0x80, 0x3F,
    0x00, 0xC0, 0x1F, 0x00, 0xE0, 0x0F, 0x00, 0xF0, 0x07, 0x0C, 0xF8, 0x03,
    0x1E, 0xFC, 0x01, 0x3F, 0xFE, 0x00, 0x7F, 0x7F, 0x00, 0xFE, 0x3F, 0x00,
    0xFC, 0x1F, 0x00, 0xF8, 0x0F, 0x00, 0xF0, 0x07, 0x00, 0xE0, 0x03, 0x00,
    0xC0, 0x01, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static unsigned char NOSD24x24[] = {
    0xC0, 0xFF, 0x0F, 0xE0, 0xFF, 0x1F, 0xE0, 0x79, 0x1E, 0x20, 0x49, 0x12,
    0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12,
    0xF0, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0x7D, 0x1F,
    0xE0, 0x38, 0x1E, 0xE0, 0x11, 0x1F, 0xF0, 0x83, 0x1F, 0xF8, 0xC7, 0x1F,
    0xF8, 0x83, 0x1F, 0xF8, 0x11, 0x1F, 0xF8, 0x38, 0x1E, 0xF8, 0x7D, 0x1F,
    0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0x18, 0x00, 0x18, 0xF0, 0xFF, 0x0F};
static unsigned char SDSave24x24[] = {
    0xC0, 0xFF, 0x0F, 0xE0, 0xFF, 0x1F, 0xE0, 0x79, 0x1E, 0x20, 0x49, 0x12,
    0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12,
    0xF0, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xEF, 0x1F,
    0xE0, 0xEF, 0x1F, 0xE0, 0xEF, 0x1F, 0xF0, 0xEF, 0x1F, 0xF8, 0xEF, 0x1F,
    0xF8, 0x6D, 0x1F, 0xF8, 0xAB, 0x1F, 0xF8, 0xC7, 0x1F, 0xF8, 0xEF, 0x1F,
    0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0x18, 0x00, 0x18, 0xF0, 0xFF, 0x0F};
static unsigned char SDOFF24x24[] = {
    0xC0, 0xFF, 0x0F, 0xE0, 0xFF, 0x1F, 0xE0, 0x79, 0x1E, 0x20, 0x49, 0x12,
    0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12,
    0xF0, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F,
    0xE0, 0xFF, 0x1F, 0x60, 0x86, 0x10, 0xB0, 0xF5, 0x1E, 0xB8, 0xF5, 0x1E,
    0xB8, 0xC5, 0x18, 0xB8, 0xF5, 0x1E, 0xB8, 0xF5, 0x1E, 0x78, 0xF6, 0x1E,
    0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0x18, 0x00, 0x18, 0xF0, 0xFF, 0x0F};
static unsigned char SD24x24[] = {
    0xC0, 0xFF, 0x0F, 0xE0, 0xFF, 0x1F, 0xE0, 0x79, 0x1E, 0x20, 0x49, 0x12,
    0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12, 0x20, 0x49, 0x12,
    0xF0, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F,
    0xE0, 0xFF, 0x1F, 0xE0, 0x18, 0x1E, 0x70, 0xD7, 0x1D, 0x78, 0xDF, 0x1D,
    0xF8, 0xD8, 0x1D, 0xF8, 0xD7, 0x1D, 0x78, 0xD7, 0x1D, 0xF8, 0x18, 0x1E,
    0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0x18, 0x00, 0x18, 0xF0, 0xFF, 0x0F};

static unsigned char Timer0_24x24[] = {
    0xFC, 0xFF, 0x3F, 0xFC, 0xFF, 0x3F, 0x10, 0x00, 0x08, 0x10, 0x00, 0x08,
    0x10, 0x00, 0x09, 0xA0, 0xC1, 0x05, 0x20, 0xF7, 0x04, 0x40, 0x7E, 0x02,
    0x80, 0x3C, 0x01, 0x00, 0x99, 0x00, 0x00, 0x42, 0x00, 0x00, 0x24, 0x00,
    0x00, 0x24, 0x00, 0x00, 0x42, 0x00, 0x00, 0x91, 0x00, 0x80, 0x00, 0x01,
    0x40, 0x08, 0x02, 0x20, 0x00, 0x04, 0x20, 0x7E, 0x04, 0x90, 0xFF, 0x09,
    0xD0, 0xFF, 0x0B, 0xD0, 0xFF, 0x0B, 0xFC, 0xFF, 0x3F, 0xFC, 0xFF, 0x3F};
static unsigned char Timer1_24x24[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0xC0, 0x03, 0x00, 0xC0,
    0x1F, 0x00, 0xF8, 0x63, 0x00, 0xC6, 0x8F, 0x00, 0xC1, 0x1F, 0x81, 0xC4,
    0x1F, 0x42, 0xC6, 0x3F, 0x24, 0xC3, 0x3F, 0x98, 0xC3, 0xBF, 0xC0, 0xC1,
    0x3F, 0xC2, 0xC3, 0x3F, 0x98, 0xC3, 0x3F, 0x24, 0xC7, 0x1F, 0x42, 0xC6,
    0x1F, 0x81, 0xCC, 0x8F, 0x00, 0xC1, 0x63, 0x00, 0xC6, 0x1F, 0x00, 0xF8,
    0x03, 0x00, 0xC0, 0x03, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static unsigned char Timer2_24x24[] = {
    0xFC, 0xFF, 0x3F, 0xFC, 0xFF, 0x3F, 0x10, 0x00, 0x08, 0x10, 0x00, 0x08,
    0x90, 0x00, 0x08, 0xA0, 0x83, 0x05, 0x20, 0xEF, 0x04, 0x40, 0x7E, 0x02,
    0x80, 0x3C, 0x01, 0x00, 0x99, 0x00, 0x00, 0x42, 0x00, 0x00, 0x24, 0x00,
    0x00, 0x24, 0x00, 0x00, 0x42, 0x00, 0x00, 0x89, 0x00, 0x80, 0x00, 0x01,
    0x40, 0x10, 0x02, 0x20, 0x00, 0x04, 0x20, 0x7E, 0x04, 0x90, 0xFF, 0x09,
    0xD0, 0xFF, 0x0B, 0xD0, 0xFF, 0x0B, 0xFC, 0xFF, 0x3F, 0xFC, 0xFF, 0x3F};
static unsigned char Timer3_24x24[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0xC0, 0x03, 0x00, 0xC0,
    0x1F, 0x00, 0xF8, 0x63, 0x00, 0xC6, 0x8F, 0x00, 0xC1, 0x1F, 0x81, 0xCC,
    0x1F, 0x42, 0xC6, 0x3F, 0x24, 0xC7, 0x3F, 0x98, 0xC3, 0x3F, 0xC2, 0xC3,
    0xBF, 0xC0, 0xC1, 0x3F, 0x98, 0xC3, 0x3F, 0x24, 0xC3, 0x1F, 0x42, 0xC6,
    0x1F, 0x81, 0xC4, 0x8F, 0x00, 0xC1, 0x63, 0x00, 0xC6, 0x1F, 0x00, 0xF8,
    0x03, 0x00, 0xC0, 0x03, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
static unsigned char BlankClock24x24[] = {
    0x00, 0x7E, 0x00, 0x80, 0xFF, 0x01, 0xE0, 0x81, 0x07, 0x70, 0x00, 0x0E,
    0x38, 0x00, 0x1C, 0x1C, 0x00, 0x38, 0x0C, 0x00, 0x30, 0x06, 0x00, 0x60,
    0x06, 0x00, 0x60, 0x03, 0x00, 0xC0, 0x03, 0x00, 0xC0, 0x03, 0x18, 0xC0,
    0x03, 0x18, 0xC0, 0x03, 0x00, 0xC0, 0x03, 0x00, 0xC0, 0x06, 0x00, 0x60,
    0x06, 0x00, 0x60, 0x0C, 0x00, 0x30, 0x1C, 0x00, 0x38, 0x38, 0x00, 0x1C,
    0x70, 0x00, 0x0E, 0xE0, 0x81, 0x07, 0x80, 0xFF, 0x01, 0x00, 0x7E, 0x00};
static unsigned char Clock24x24[] = {
    0x00, 0x7E, 0x00, 0xC0, 0xFF, 0x03, 0xE0, 0x81, 0x07, 0x70, 0x08, 0x0E,
    0x18, 0x08, 0x18, 0x0C, 0x08, 0x38, 0x0E, 0x08, 0x70, 0x06, 0x08, 0x60,
    0x06, 0x08, 0x60, 0x03, 0x08, 0xC0, 0x03, 0x08, 0xC0, 0x03, 0x08, 0xC0,
    0x03, 0x10, 0xC0, 0x03, 0x20, 0xC0, 0x03, 0x40, 0xC0, 0x06, 0x80, 0x60,
    0x06, 0x00, 0x60, 0x0E, 0x00, 0x70, 0x0C, 0x00, 0x30, 0x38, 0x00, 0x18,
    0x70, 0x00, 0x0E, 0xE0, 0x81, 0x07, 0xC0, 0xFF, 0x03, 0x00, 0x7E, 0x00};
static unsigned char Home24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x3C, 0x00, 0x00, 0x7E, 0x00, 0x00, 0xFF, 0x00,
    0x80, 0xFF, 0x01, 0xC0, 0xFF, 0x03, 0xE0, 0xFF, 0x07, 0xF0, 0xFF, 0x0F,
    0xF8, 0xFF, 0x1F, 0xFC, 0xFF, 0x3F, 0xFE, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF,
    0x08, 0x00, 0x10, 0x08, 0x00, 0x10, 0x08, 0x00, 0x10, 0x08, 0x7E, 0x10,
    0x08, 0x7E, 0x10, 0x08, 0x7E, 0x10, 0x08, 0x7E, 0x10, 0x08, 0x7E, 0x10,
    0x08, 0x7E, 0x10, 0x08, 0x7E, 0x10, 0x08, 0x7E, 0x10, 0xF8, 0xFF, 0x1F};
static unsigned char Cal24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x7E, 0x00, 0x80, 0x99, 0x01,
    0x40, 0x18, 0x02, 0x20, 0x7E, 0x04, 0x10, 0x99, 0x08, 0x88, 0x00, 0x11,
    0x48, 0x00, 0x12, 0x24, 0x40, 0x24, 0x24, 0x30, 0x24, 0x7F, 0x38, 0xFE,
    0x7F, 0x1C, 0xFE, 0x24, 0x0C, 0x24, 0x24, 0x02, 0x24, 0x48, 0x00, 0x12,
    0x88, 0x00, 0x11, 0x10, 0x99, 0x08, 0x20, 0x7E, 0x04, 0x40, 0x18, 0x02,
    0x80, 0x99, 0x01, 0x00, 0x7E, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};

static unsigned char Unit_rad24x24[] = {
    0x04, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x04, 0x00, 0x20, 0x04, 0x00, 0x20, 0x04, 0x00, 0x20,
    0x04, 0x00, 0x20, 0xA4, 0x39, 0x3C, 0x64, 0x40, 0x22, 0x24, 0x78, 0x22,
    0x24, 0x44, 0x22, 0x24, 0x44, 0x22, 0x24, 0xB8, 0x1C, 0x04, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x20,
    0x04, 0x00, 0x60, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x60, 0x00, 0x00, 0x20};

static unsigned char Unit_mmm24x24[] = {
    0x04, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x64, 0x59, 0x20, 0xA4, 0xAA, 0x10,
    0xA4, 0xAA, 0x08, 0xA4, 0xAA, 0x04, 0x04, 0x00, 0x02, 0x04, 0x00, 0x01,
    0x04, 0x80, 0x00, 0x04, 0x40, 0x16, 0x04, 0x20, 0x2A, 0x04, 0x10, 0x2A,
    0x04, 0x08, 0x2A, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x20,
    0x04, 0x00, 0x60, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x60, 0x00, 0x00, 0x20};

static unsigned char Unit_deg24x24[] = {
    0x04, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x04, 0x02, 0x00, 0x04, 0x02, 0x00, 0x04, 0x02, 0x00, 0x04, 0x02, 0x00,
    0xC4, 0x73, 0x1C, 0x24, 0x8A, 0x22, 0x24, 0x8A, 0x22, 0x24, 0x7A, 0x22,
    0x24, 0x0A, 0x22, 0xC4, 0xF1, 0x3C, 0x04, 0x00, 0x20, 0x04, 0x00, 0x22,
    0x04, 0x00, 0x1C, 0x04, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04, 0x00, 0x20,
    0x04, 0x00, 0x60, 0xFC, 0xFF, 0xFF, 0x00, 0x00, 0x60, 0x00, 0x00, 0x20};

static unsigned char Light0_24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7E, 0x18,
    0x98, 0x81, 0x19, 0x40, 0x00, 0x02, 0x20, 0x00, 0x04, 0x10, 0x00, 0x08,
    0x10, 0x00, 0x08, 0x08, 0x00, 0x10, 0x08, 0x00, 0x10, 0x0B, 0x00, 0xD0,
    0x0B, 0x00, 0xD0, 0x08, 0x00, 0x10, 0x08, 0x00, 0x10, 0x10, 0x00, 0x08,
    0x10, 0x00, 0x08, 0x20, 0x00, 0x04, 0x40, 0x00, 0x02, 0x98, 0x81, 0x19,
    0x18, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};
static unsigned char Light1_24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7E, 0x18,
    0x98, 0x81, 0x19, 0x40, 0x00, 0x02, 0x60, 0x00, 0x04, 0x70, 0x00, 0x08,
    0x70, 0x00, 0x08, 0x78, 0x00, 0x10, 0x78, 0x00, 0x10, 0x7B, 0x00, 0xD0,
    0x7B, 0x00, 0xD0, 0x78, 0x00, 0x10, 0x78, 0x00, 0x10, 0x70, 0x00, 0x08,
    0x70, 0x00, 0x08, 0x60, 0x00, 0x04, 0x40, 0x00, 0x02, 0x98, 0x81, 0x19,
    0x18, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};
static unsigned char Light2_24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7E, 0x18,
    0x98, 0x83, 0x19, 0xC0, 0x03, 0x02, 0xE0, 0x03, 0x04, 0xF0, 0x03, 0x08,
    0xF0, 0x03, 0x08, 0xF8, 0x03, 0x10, 0xF8, 0x03, 0x10, 0xFB, 0x03, 0xD0,
    0xFB, 0x03, 0xD0, 0xF8, 0x03, 0x10, 0xF8, 0x03, 0x10, 0xF0, 0x03, 0x08,
    0xF0, 0x03, 0x08, 0xE0, 0x03, 0x04, 0xC0, 0x03, 0x02, 0x98, 0x83, 0x19,
    0x18, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};
static unsigned char Light3_24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7E, 0x18,
    0x98, 0xBF, 0x19, 0xC0, 0x3F, 0x02, 0xE0, 0x3F, 0x04, 0xF0, 0x3F, 0x08,
    0xF0, 0x3F, 0x08, 0xF8, 0x3F, 0x10, 0xF8, 0x3F, 0x10, 0xFB, 0x3F, 0xD0,
    0xFB, 0x3F, 0xD0, 0xF8, 0x3F, 0x10, 0xF8, 0x3F, 0x10, 0xF0, 0x3F, 0x08,
    0xF0, 0x3F, 0x08, 0xE0, 0x3F, 0x04, 0xC0, 0x3F, 0x02, 0x98, 0xBF, 0x19,
    0x18, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};
static unsigned char Light4_24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7E, 0x18,
    0x98, 0xFF, 0x19, 0xC0, 0xFF, 0x03, 0xE0, 0xFF, 0x05, 0xF0, 0xFF, 0x09,
    0xF0, 0xFF, 0x09, 0xF8, 0xFF, 0x11, 0xF8, 0xFF, 0x11, 0xFB, 0xFF, 0xD1,
    0xFB, 0xFF, 0xD1, 0xF8, 0xFF, 0x11, 0xF8, 0xFF, 0x11, 0xF0, 0xFF, 0x09,
    0xF0, 0xFF, 0x09, 0xE0, 0xFF, 0x05, 0xC0, 0xFF, 0x03, 0x98, 0xFF, 0x19,
    0x18, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};
static unsigned char Light5_24x24[] = {
    0x00, 0x18, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x7E, 0x18,
    0x98, 0xFF, 0x19, 0xC0, 0xFF, 0x03, 0xE0, 0xFF, 0x07, 0xF0, 0xFF, 0x0F,
    0xF0, 0xFF, 0x0F, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xFB, 0xFF, 0xDF,
    0xFB, 0xFF, 0xDF, 0xF8, 0xFF, 0x1F, 0xF8, 0xFF, 0x1F, 0xF0, 0xFF, 0x0F,
    0xF0, 0xFF, 0x0F, 0xE0, 0xFF, 0x07, 0xC0, 0xFF, 0x03, 0x98, 0xFF, 0x19,
    0x18, 0x7E, 0x18, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x18, 0x00};
static unsigned char Bulb_7x8[] =  { 0x08, 0x41, 0x1C, 0x22, 0x2A, 0x14, 0x1C, 0x08 };
unsigned char *Unit24x24[3] = {&Unit_deg24x24[0], &Unit_mmm24x24[0], &Unit_rad24x24[0]};
unsigned char *Light24x24[6] = {&Light0_24x24[0],&Light1_24x24[0],&Light2_24x24[0],&Light3_24x24[0],&Light4_24x24[0],&Light5_24x24[0]};
#endif