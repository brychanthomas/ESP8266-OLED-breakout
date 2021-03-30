#ifndef INCLUDED
#define INCLUDED
#include <Arduino.h>
#include "SSD1306Wire.h"
#include "Sprite.h"
#include "constants.h"
#endif

class Brick: public Sprite {
  public:
    Brick(int, int, int, int, SSD1306Wire*);
    boolean exists;
    int x;
    int y;
    int width;
    int height;
    void destroy();
    void draw();
};
