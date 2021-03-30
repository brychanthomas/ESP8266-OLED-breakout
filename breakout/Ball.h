#ifndef INCLUDED
#define INCLUDED
#include <Arduino.h>
#include "SSD1306Wire.h"
#include "Sprite.h"
#include "constants.h"
#endif

class Ball: public Sprite {
  private:
    double yVel;
    double xVel;
    int diameter;
    
  public:
    Ball(int, int, double, double, int, SSD1306Wire*);
    void draw();
    void update(int, int, int);
    void checkPaddleCollision(int, int, int);
    void bounceOffTopOrBottom();
    void bounceOffSide();
    int getX();
    void setPosition(int, int);
};
