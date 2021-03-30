#include <Wire.h>
#include "SSD1306Wire.h"

class Ball {
  private:
    double x;
    double y;
    double yVel;
    double xVel;
    int radius;
    SSD1306Wire* disp;
    
  public:
    Ball(int, int, double, double, int, SSD1306Wire*);
    void update(void);
    void draw();
    void bounceOffBottom(void);
    void bounceOffTop(void);
    void bounceOffRight(void);
    void bounceOffLeft(void);
};

Ball::Ball(int xcoord, int ycoord, double xVelocity, double yVelocity, int rad, SSD1306Wire* display) {
  x = xcoord;
  y = ycoord;
  xVel = xVelocity;
  yVel = yVelocity;
  radius = rad;
  disp = display;
}

void Ball::update(void) {
  x += xVel;
  y += yVel;
}

void Ball::draw(void) {
  disp->fillCircle(round(x), round(y), radius);
}

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
