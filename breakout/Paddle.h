#ifndef INCLUDED
#define INCLUDED
#include "sprite.h"
#include "SSD1306Wire.h"
#include <Arduino.h>
#include "constants.h"
#endif

/**
 * Represents movable paddle at the bottom of the screen
 */
class Paddle: public Sprite {
  private:
    int width;
  public:
    Paddle(int, int, SSD1306Wire*);
    int getX();
    int getY();
    int getWidth();
    void update();
    void draw();
};
