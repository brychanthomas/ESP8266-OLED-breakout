#include "Brick.h"

class Bricks {
  private:
    Brick bricks[32];
    unsigned char score;

  public:
    Bricks(SSD1306Wire*);
    void draw();
    void update(Ball*);
    unsigned char getScore();
};
