#include "SSD1306Wire.h"
#include "Paddle.h"
#include "Bricks.h"
#include "images.h"

class BreakoutGame {
  private:
    Paddle* paddle;
    Ball* ball;
    Bricks* bricks;
    SSD1306Wire* display;
    void reset();
    void update();
    void draw();
    void showStartScreen();

  public:
    BreakoutGame(SSD1306Wire*);
    void runFrame();
};
