#include "Brick.h"

Brick::Brick(int x, int y, int height, int width, SSD1306Wire* display) {
  this->x = x;
  this->y = y;
  this->height = height;
  this->width = width;
  disp = display;
  exists = true;
}

Brick::Brick() {
  
}

void Brick::destroy() {
  exists = false;
}

void Brick::draw() {
  if (exists) {
    disp->fillRect(x, y, width, height);
  }
}
