#include "Ball.h"

Ball::Ball(int xcoord, int ycoord, double xVelocity, double yVelocity, int diameter, SSD1306Wire* display) {
  x = xcoord;
  y = ycoord;
  xVel = xVelocity;
  yVel = yVelocity;
  this->diameter = diameter;
  disp = display;
}

/**
 * Move based on velocity, check for collisions with paddle and sides
 */
void Ball::update(int paddleX, int paddleY, int paddleWidth) {
  checkPaddleCollision(paddleX, paddleY, paddleWidth);
  x += xVel;
  y += yVel;
  if (y-diameter/2 <= 1 || y+diameter/2 >= 63) { //right and left sides
    bounceOffSide();
    y += 2*yVel; //*2 to undo earlier position update before bounce
  }
  if (x-diameter/2 <= 1) { //top side
    bounceOffTopOrBottom();
    x += 2*xVel;
  }
}

/**
 * Check if ball is colliding with paddle - bounce and randomise horizontal
 * velocity if so
 */
void Ball::checkPaddleCollision(int paddleX, int paddleY, int paddleWidth) {
  if (paddleX - x <= diameter/2 && y+diameter/2 >= paddleY-(paddleWidth/2) && y-diameter/2 <= paddleY+(paddleWidth/2)) {
    bounceOffTopOrBottom();
    yVel = ((double)random(25, 80)/FPS)*((yVel>=0) ? 1 : -1);
  }
}

/**
 * Draw the ball on the screen
 */
void Ball::draw() {
  disp->fillCircle(round(x), round(y), diameter);
}

/**
 * Bounce off the top or bottom of something (reverse vertical velocity)
 */
void Ball::bounceOffTopOrBottom() {
  xVel = -xVel;
}

/**
 * Bounce off the side of something (reverse horizontal velocity)
 */
void Ball::bounceOffSide() {
  yVel = -yVel;
}

/**
 * Returns x coordinate of ball
 */
int Ball::getX() {
  return x;
}

/**
 * Set a specific x, y position
 */
void Ball::setPosition(int x, int y) {
  this->x = x;
  this->y = y;
}

/**
 * Check if ball has collided with brick at given position with given
 * dimensions. Bounce if true. Returns true if block should be destroyed.
 */
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
