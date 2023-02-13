#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <Engine/Manager/AssetManager.hpp>
#include <Engine/Manager/AudioManager.hpp>
#include <Engine/Manager/FontManager.hpp>
#include <Engine/Manager/WindowManager.hpp>

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