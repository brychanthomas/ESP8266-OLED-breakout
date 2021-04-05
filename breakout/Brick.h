#ifndef INCLUDED
#define INCLUDED
#include <Arduino.h>
#include "SSD1306Wire.h"
#include "Sprite.h"
#include "constants.h"
#endif

#include "Ball.h"

/**
 * Class to represent a single brick - inherits from Sprite class
 */
class Brick: public Sprite {
  public:
    Brick(int, int, int, int, SSD1306Wire*);
    Brick();
    boolean exists;
    int x;
    int y;
    int width;
    int height;
    void destroy();
    void draw();
};
