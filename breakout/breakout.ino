#include <Wire.h>
#include "BreakoutGame.h"

SSD1306Wire display(0x3c, 5, 4);  // ADDRESS, SDA, SCL

BreakoutGame* game;

void setup() {
  Serial.begin(115200);
  display.init();
  display.setColor(WHITE);
  pinMode(RIGHTBTN, INPUT_PULLUP);
  pinMode(LEFTBTN, INPUT_PULLUP);
  pinMode(UPBTN, INPUT_PULLUP);
  pinMode(PUSHBTN, INPUT_PULLUP);
  game = new BreakoutGame(&display);
}

void loop() {
  game->runFrame();
}
