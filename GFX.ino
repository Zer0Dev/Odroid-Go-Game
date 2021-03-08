#define LGFX_ODROID_GO
#include <LovyanGFX.hpp>
#include "Button.h"
#include "config.h"

static LGFX lcd;
static LGFX_Sprite screen(&lcd);

Button JOY_Y = Button(BUTTON_JOY_Y, true, DEBOUNCE_MS);
Button JOY_X = Button(BUTTON_JOY_X, true, DEBOUNCE_MS);
Button BtnA = Button(BUTTON_A_PIN, true, DEBOUNCE_MS);
Button BtnB = Button(BUTTON_B_PIN, true, DEBOUNCE_MS);
Button BtnSelect = Button(BUTTON_SELECT, true, DEBOUNCE_MS);
Button BtnStart = Button(BUTTON_START, true, DEBOUNCE_MS);


uint32_t tiles[2][16][16] = {
  {
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU},
    {BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU, BLU}
  },
  {
    {GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN},
    {GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN, GRN},
    {GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW},
    {BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN, BRW, GRN},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW},
    {BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW, BRW}
  }
};

uint8_t gameMap[40][40] = {
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

uint32_t pixelCamPosX = 0;
uint32_t pixelCamPosY = 0;
uint32_t tileCamPosX = 0;
uint32_t tileCamPosY = 0;
uint32_t tileCamLeftOffset = 0;
uint32_t tileCamRightOffset = 0;
uint32_t tileCamTopOffset = 0;
uint32_t tileCamBottomOffset = 0;
uint32_t frames = 0;
uint32_t sek = millis()/100;

void setup(void)
{
  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);
  pinMode(BUTTON_SELECT, INPUT_PULLUP);
  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_JOY_Y, INPUT_PULLDOWN);
  pinMode(BUTTON_JOY_X, INPUT_PULLDOWN);

  lcd.init();
  lcd.setRotation(1);
  lcd.setBrightness(128);
  lcd.setColorDepth(8);
  screen.createSprite(240, 240);
}

void loop(void)
{
  lcd.startWrite();
  //Button update
  BtnA.read();
  BtnB.read();
  BtnSelect.read();
  BtnStart.read();
  JOY_Y.readAxis();
  JOY_X.readAxis();

  if (JOY_X.isAxisPressed() == 1) {
    pixelCamPosX += 6;
  }

  if (JOY_X.isAxisPressed() == 2) {
    pixelCamPosX -= 6;
  }

  if (JOY_Y.isAxisPressed() == 1) {
    pixelCamPosY += 6;
  }

  if (JOY_Y.isAxisPressed() == 2) {
    pixelCamPosY -= 6;
  }

  tileCamPosX = pixelCamPosX / 16;
  tileCamPosY = pixelCamPosY / 16;
  tileCamLeftOffset = pixelCamPosX % 16;
  tileCamRightOffset = 16 - tileCamRightOffset;
  tileCamTopOffset = pixelCamPosY % 16;
  tileCamBottomOffset = 16 - tileCamTopOffset;

  for (uint8_t X = 0; X < 16; ++X) {
    for (uint8_t Y = 0; Y < 16; ++Y) {
      uint8_t yStart = 0;
      uint8_t yEnd = 16;
      if (Y == 0) {
        yStart = tileCamTopOffset;
      }
      if (Y == 16) {
        if (tileCamTopOffset == 0) {
          return;
        }
        yEnd = tileCamBottomOffset;
      }
      for (uint8_t y = yStart; y < yEnd; ++y) {
        uint8_t xStart = 0;
        uint8_t xEnd = 16;
        if (X == 0) {
          xStart = tileCamLeftOffset;
        }
        if (X == 16) {
          if (tileCamLeftOffset == 0) {
            return;
          }
          xEnd = tileCamRightOffset;
        }
        for (uint8_t x = xStart; x < xEnd; ++x) {
          screen.drawPixel(x + (X * 16) - tileCamLeftOffset, y + (Y * 16) - tileCamTopOffset, tiles[gameMap[Y + tileCamPosY][X + tileCamPosX]][y][x]);
        }
      }
    }
  }

  screen.pushSprite(40, 0);
  lcd.endWrite();
}
