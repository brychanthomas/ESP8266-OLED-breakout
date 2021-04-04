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
  if (y-diameter/2 <= 1 || y+diameter/2 >= 63) {
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
    yVel = ((double)random(25, 80)/FPS)*((yVel>=0) ? 1 : -1);
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

boolean Ball::checkBrickCollision(int brickX, int brickY, int height, int width) {

  boolean destroyBlock = false;

  double radius = diameter/2.0;

  int deltaX = x - max((double)brickX, min(x, (double)brickX+width));
  int deltaY = y - max((double)brickY, min(y, (double)brickY+height));
  if (deltaX*deltaX + deltaY*deltaY <= radius*radius) { //if ball and brick overlapping
    if (x >= brickX+width || x <= brickX) {
      bounceOffTopOrBottom();
      destroyBlock = true;
    }

    if (y >= brickY+height || y <= brickY) {
      bounceOffSide();
      destroyBlock = true;
    }
  }
  return destroyBlock;
}
