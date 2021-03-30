#include "Bricks.h"

Bricks::Bricks (SSD1306Wire* display){
  for (int col = 0; col < 4; col++) {
    for (int row = 0; row < 8; row++) {
      bricks[row*4+col] = Brick(row*8+1, col*16+1, 14, 6, display);
    }
  }
}

void Bricks::draw() {
  for (int i=0; i<sizeof(bricks)/sizeof(bricks[i]); i++) {
    bricks[i].draw();
  }
}
