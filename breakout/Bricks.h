#include "Brick.h"

/**
 * Class to represent all of the bricks in the game
 */
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
