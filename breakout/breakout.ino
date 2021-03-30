#include <Wire.h>
#include "SSD1306Wire.h"

#include "Ball.h"
#include "Paddle.h"
#include "Bricks.h"
#include "constants.h"


SSD1306Wire display(0x3c, 5, 4);  // ADDRESS, SDA, SCL

void setup() {
  Serial.begin(115200);
  display.init();
  display.setColor(WHITE);
  pinMode(RIGHTBTN, INPUT_PULLUP);
  pinMode(LEFTBTN, INPUT_PULLUP);
  pinMode(UPBTN, INPUT_PULLUP);
  pinMode(PUSHBTN, INPUT_PULLUP);
}

Ball ball(80, 32, 45.0/FPS, 45.0/FPS, 3, &display);
Paddle paddle(120, 20, &display);

Bricks bricks(&display);

void loop() {
  display.clear();

  paddle.update();
  ball.update(paddle.getX(), paddle.getY(), paddle.getWidth());

  ball.draw();
  paddle.draw();
  bricks.draw();
  display.display();

  delay(1000/FPS);

  if (ball.getX() > paddle.getX()) {
    delay(1000);
    ball.setPosition(30, 32);
  }

}
