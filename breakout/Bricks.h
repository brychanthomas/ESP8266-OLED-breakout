#include "Brick.h"

class Bricks {
  private:
    Brick bricks[32];

  public:
    Bricks(SSD1306Wire*);
    void draw();
    void update(Ball*);
};
