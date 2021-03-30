#include "Ball.h"

Ball::Ball(int xcoord, int ycoord, double xVelocity, double yVelocity, int diameter, SSD1306Wire* display) {
  x = xcoord;
  y = ycoord;
  xVel = xVelocity;
  yVel = yVelocity;
  this->diameter = diameter;
  disp = display;
}

void Ball::update(void) {
  x += xVel;
  y += yVel;
}

void Ball::draw(void) {
  disp->fillCircle(round(x), round(y), diameter);
}
