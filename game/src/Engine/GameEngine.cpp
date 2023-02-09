#include <spdlog/spdlog.h>

#include <Engine/GameEngine.hpp>

/**
 * Initialise a GameEngine instance.
 */
void GameEngine::init() {
  int initResult = SDL_Init(SDL_INIT_EVERYTHING);
  if (initResult == 0) {
    spdlog::error("Failed to start SDL2: {}",
                  SDL_GetError()) throw runtime_error();
  }
  windowManager.init();
  assetManager.init();
}

/**
 * Quit a GameEngine instance.
 */
void GameEngine::quit() {
  assetManager.quit();
  windowManager.quit();
  SDL_Quit();
}