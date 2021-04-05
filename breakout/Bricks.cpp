#include "Bricks.h"

/**
 * Create 32 bricks and initialise score to 0
 */
Bricks::Bricks (SSD1306Wire* display){
  score = 0;
  for (int col = 0; col < 4; col++) {
    for (int row = 0; row < 8; row++) {
      bricks[31-(row*4+col)] = Brick(row*8+1, col*16+1, 14, 6, display);
    }
  }
}

/**
 * Draw the bricks
 */
void Bricks::draw() {
  for (int i=0; i<sizeof(bricks)/sizeof(bricks[i]); i++) {
    bricks[i].draw();
  }
}

/**
 * Check for collision between ball and each brick, bounce ball and destroy
 * brick if colliding
 */
void Bricks::update(Ball* b) {
  for (int i=0; i<sizeof(bricks)/sizeof(bricks[i]); i++) {
    if (bricks[i].exists) {
      if (b->checkBrickCollision(bricks[i].x, bricks[i].y, bricks[i].height, bricks[i].width)) {
        bricks[i].exists = false;
        score++;
        break;
      }
    }
  }
}

/**
 * Get the current score - incremented on each brick destroyed
 */
unsigned char Bricks::getScore() {
  return score;
}
