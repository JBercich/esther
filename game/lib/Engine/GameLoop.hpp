#ifndef GAME_LOOP_H
#define GAME_LOOP_H

#include <Engine/GameEngine.hpp>
#include <Game/Game.hpp>

class GameLoop {
public:
  Game game;
  GameEngine gameEngine;
  void input();
  void update();
  void draw();
  void run();
};

#endif