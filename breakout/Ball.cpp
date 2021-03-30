#include "Ball.h"

Ball::Ball(int xcoord, int ycoord, double xVelocity, double yVelocity, int diameter, SSD1306Wire* display) {
  x = xcoord;
  y = ycoord;
  xVel = xVelocity;
  yVel = yVelocity;
  this->diameter = diameter;
  disp = display;
}

void Ball::update(int paddleX, int paddleY, int paddleWidth) {
  checkPaddleCollision(paddleX, paddleY, paddleWidth);
  x += xVel;
  y += yVel;
  if (y-diameter/2 <= 1 || y+diameter/2 >= 64) {
    bounceOffSide();
    y += 2*yVel;
  }
  if (x-diameter/2 <= 1) {
    bounceOffTopOrBottom();
    x += 2*xVel;
  }
}

void Ball::checkPaddleCollision(int paddleX, int paddleY, int paddleWidth) {
  if (paddleX - x <= diameter/2 && y+diameter/2 >= paddleY-(paddleWidth/2) && y-diameter/2 <= paddleY+(paddleWidth/2)) {
    bounceOffTopOrBottom();
    yVel = ((double)random(25, 50)/FPS)*(yVel/abs(yVel));
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

int Ball::getX() {
  return x;
}

void Ball::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}
