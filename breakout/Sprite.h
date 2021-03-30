#include "SSD1306Wire.h"

class Sprite {
  protected:
    int x;
    int y;
    SSD1306Wire* disp;

  public:
    virtual void update()=0;
    virtual void draw()=0;
};
