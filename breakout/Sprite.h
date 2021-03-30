#include "SSD1306Wire.h"

#include "constants.h"

class Sprite {
  protected:
    double x;
    double y;
    SSD1306Wire* disp;

  public:
    virtual void draw()=0;
};
