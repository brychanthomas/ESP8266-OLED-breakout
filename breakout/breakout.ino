#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 5, 4);  // ADDRESS, SDA, SCL

void setup() {
  //Serial.begin(9600);
  display.init();
  display.setColor(WHITE);
}

int x;
int y;
void loop() {
  x = random(1, 129);
  y = random(1, 65);
  display.setPixel(x, y);
  delay(50);
  display.display(); //write data in buffer to display

}
