#include "Paddle.h"

Paddle::Paddle(int x, int width, SSD1306Wire* display) {
  disp = display;
  this->x = x;
  this->width = width;
  y = 64 / 2;
}

void Paddle::draw() {
  disp->fillRect(x, y-(width/2), 3, width);
}

void Paddle::update() {
  if (digitalRead(RIGHTBTN) == 0) {
    y += 40.0/FPS;
  } else if (digitalRead(LEFTBTN) == 0) {
    y -= 40.0/FPS;
  }
}
