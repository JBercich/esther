#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <Engine/AssetManager.hpp>
#include <Engine/AudioManager.hpp>
#include <Engine/FontManager.hpp>
#include <Engine/WindowManager.hpp>

class GameEngine {
public:
  AssetManager assetManager;
  WindowManager windowManager;
  AudioManager audioManager;
  FontManager fontManager;
  void init();
  void quit();
};

#endif