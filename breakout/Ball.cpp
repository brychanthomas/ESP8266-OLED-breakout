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
    yVel = ((double)random(25, 50)/FPS)*((yVel>=0) ? 1 : -1);
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
  // //collision with bottom
  // if (brickY-2 <= y+(diameter/2.0) && y-(diameter/2.0) <= brickY+width+2 && abs(x-(brickX+height)) <= diameter/2.0 && xVel < 0) {
  //   bounceOffTopOrBottom();
  //   return true;
  // }
  // //collision with sides
  // if (x+(diameter/2.0) >= brickX && x-(diameter/2.0) <= brickX+height && y+(diameter/2.0) >= brickY && y-(diameter/2.0) <= brickY+width) {
  //   bounceOffSide();
  //   return true;
  // }
  double radius = diameter/2.0;
  double topOfCircleX = x - radius;
  double bottomOfCircleX = x + radius;
  double rightOfCircleY = y + radius;
  double leftOfCircleY = y - radius;
  //collision with bottom
  if (topOfCircleX >= brickX && topOfCircleX <= brickX+height && rightOfCircleY >= brickY-1 && leftOfCircleY <= brickY+width+1 && xVel < 0) {
    bounceOffTopOrBottom();
    return true;
  }

  //collision with top
  if (bottomOfCircleX >= brickX && bottomOfCircleX <= brickX+height && rightOfCircleY >= brickY && leftOfCircleY <= brickY+width && xVel > 0) {
    bounceOffTopOrBottom();
    return true;
  }

  //collision with left side
  if (rightOfCircleY >= brickY && leftOfCircleY <= brickY && topOfCircleX <= brickX+height && brickX <= bottomOfCircleX && yVel > 0) {
    bounceOffSide();
    return true;
  }

  //collision with right side
  if (leftOfCircleY <= brickY + width && rightOfCircleY >= brickY + width && topOfCircleX <= brickX+height && brickX <= bottomOfCircleX && yVel < 0) {
    bounceOffSide();
    return true;
  }
  return false;
}
