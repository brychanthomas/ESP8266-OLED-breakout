#include <Wire.h>
#include "SSD1306Wire.h"

#include "Ball.h"

#define FPS 30


class Brick;

class Paddle;

SSD1306Wire display(0x3c, 5, 4);  // ADDRESS, SDA, SCL

void setup() {
  Serial.begin(115200);
  display.init();
  display.setColor(WHITE);
  Serial.println("A");
}

Ball ball(5, 30, 45/FPS, 90/FPS, 3, &display);
void loop() {
  display.clear();
  ball.draw();
  display.display();
  Serial.println("B");
  ball.update();
  delay(1000/FPS);
  Serial.println("C");

}
