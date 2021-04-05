#include "Paddle.h"

Paddle::Paddle(int x, int width, SSD1306Wire* display) {
  disp = display;
  this->x = x;
  this->width = width;
  y = 64 / 2;
}

/**
 * Draw the paddle on the screen
 */
void Paddle::draw() {
  disp->fillRect(x, y-(width/2), 3, width);
}

/**
 * Update the position of the paddle based on which joystick buttons are pressed
 */
void Paddle::update() {
  if (digitalRead(RIGHTBTN) == 0 && y+(width/2) <= 64) {
    y += 60.0/FPS; //60 pixels/second
  } else if (digitalRead(LEFTBTN) == 0 && y-(width/2) >= 1) {
    y -= 60.0/FPS;
  }
}

/**
 * Returns y coordinate of paddle
 */
int Paddle::getY() {
  return y;
}

/**
 * Returns x coordinate of paddle
 */
int Paddle::getX() {
  return x;
}

/**
 * Returns width of paddle
 */
int Paddle::getWidth() {
  return width;
}
