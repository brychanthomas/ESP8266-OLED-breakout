#include "Ball.h"

Ball::Ball(int xcoord, int ycoord, double xVelocity, double yVelocity, int diameter, SSD1306Wire* display) {
  x = xcoord;
  y = ycoord;
  xVel = xVelocity;
  yVel = yVelocity;
  this->diameter = diameter;
  disp = display;
}

void Ball::update() {
  x += xVel;
  y += yVel;
  if (y-diameter/2 <= 1 || y+diameter/2 >= 64) {
    bounceOffSide();
    y += 2*yVel;
  }
  if (x-diameter/2 <= 1 || x+diameter/2 >= 128) {
    bounceOffTopOrBottom();
    x += 2*xVel;
  }
}

void Ball::draw() {
  disp->fillCircle(round(x), round(y), diameter);
}

void Ball::bounceOffTopOrBottom() {
  xVel = -xVel;
}

void Ball::bounceOffSide() {
  yVel = -yVel;
}
