#include "BreakoutGame.h"

BreakoutGame::BreakoutGame(SSD1306Wire* disp) {
  display = disp;
  ball = new Ball(80, 32, 70.0/FPS, 70.0/FPS, 3, display);
  paddle = new Paddle(120, 20, display);
  bricks = new Bricks(display);

  showStartScreen();
}

void BreakoutGame::update() {
  paddle->update();
  ball->update(paddle->getX(), paddle->getY(), paddle->getWidth());
  bricks->update(ball);
}

void BreakoutGame::draw() {
  display->clear();
  ball->draw();
  paddle->draw();
  bricks->draw();
  display->display();
}

void BreakoutGame::runFrame() {
  update();
  draw();

  delay(1000/FPS);

  if (ball->getX() > paddle->getX()) {
    display->drawXbm(75, 8, pushToPlayWidth, pushToPlayHeight, pushToPlayXBM);
    display->invertDisplay();
    display->display();
    while(digitalRead(PUSHBTN) == HIGH) {delay(50);}
    display->normalDisplay();
    ball->setPosition(80, 32);
  }

  if (bricks->getScore() == 32) { //if all bricks destroyed
    display->clear();
    display->drawXbm(60, 3, winnerWidth, winnerHeight, winnerXBM);
    display->invertDisplay();
    display->display();
    delay(5000);
    reset();
    showStartScreen();
  }
}

void BreakoutGame::reset() {
  delete ball;
  delete paddle;
  delete bricks;

  ball = new Ball(80, 32, 70.0/FPS, 70.0/FPS, 3, display);
  paddle = new Paddle(120, 20, display);
  bricks = new Bricks(display);
}

void BreakoutGame::showStartScreen() {
  display->clear();
  display->drawXbm(60, 8, pushToPlayWidth, pushToPlayHeight, pushToPlayXBM);
  display->invertDisplay();
  display->display();
  while(digitalRead(PUSHBTN) == HIGH) {delay(50);}
  display->normalDisplay();
}
