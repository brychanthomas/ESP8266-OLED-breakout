#include <Wire.h>
#include "SSD1306Wire.h"

#include "Ball.h"


class Brick;

class Paddle;

SSD1306Wire display(0x3c, 5, 4);  // ADDRESS, SDA, SCL

void setup() {
  Serial.begin(115200);
  display.init();
  display.setColor(WHITE);
  Serial.println("A");
}

Ball ball(1, 30, 1.5, 0.0, 3, &display);
void loop() {
  display.clear();
  ball.draw();
  display.display();
  Serial.println("B");
  ball.update();
  delay(50);
  Serial.println("C");

}
