#ifndef GAME_H
#define GAME_H

#include <Engine/GameEngine.hpp>

class Game {
  private:
    bool running;
    uint frameRate;
    GameEngine gameEngine;

  public:
    Game(uint frameRate, GameEngine gameEngine): 
      gameEngine(gameEngine), 
      frameRate(frameRate) 
      {};
    ~Game(){};
    void run();
    void input();
    void update();
    void render();  
};

#endif