#include <Arduino.h>
#include "SSD1306Wire.h"

class Ball {
  private:
    double x;
    double y;
    double yVel;
    double xVel;
    int diameter;
    SSD1306Wire* disp;
    
  public:
    Ball(int, int, double, double, int, SSD1306Wire*);
    void update(void);
    void draw();
    void bounceOffBottom(void);
    void bounceOffTop(void);
    void bounceOffRight(void);
    void bounceOffLeft(void);
};
