#include <Engine/GameEngine.hpp>

#include <spdlog/spdlog.h>

// Initialise a GameEngine instance
void GameEngine::init() {
  int initResult = SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
  if (initResult != 0) {
    SPDLOG_ERROR(SDL_GetError());
  }
  windowManager.init();
  assetManager.init();
  audioManager.init();
  fontManager.init();
}

// Quit a GameEngine instance
void GameEngine::quit() {
  fontManager.quit();
  audioManager.quit();
  assetManager.quit();
  windowManager.quit();
  SDL_Quit();
}