#include "Brick.h"

/**
 * Create brick at specific coordinates with specifc size
 */
Brick::Brick(int x, int y, int height, int width, SSD1306Wire* display) {
  this->x = x;
  this->y = y;
  this->height = height;
  this->width = width;
  disp = display;
  exists = true;
}

/**
 * Create brick without position or size (should be replaced with real brick
 * soon after in Bricks constructor)
 */
Brick::Brick() {

}

/**
 * Set exists attribute to false - brick no longer shown on screen and
 * cannot collide with ball.
 */
void Brick::destroy() {
  exists = false;
}

/**
 * Draw brick to screen.
 */
void Brick::draw() {
  if (exists) {
    disp->fillRect(x, y, width, height);
  }
}
