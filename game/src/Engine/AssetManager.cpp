#include <SDL2_Image/SDL_Image.h>
#include <spdlog/spdlog.h>

#include <Engine/AssetManager.hpp>
#include <stdexcept>

/**
 * Initialise an AssetManager instance.
 */
void AssetManager::init() {
  int initResult = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  if (initResult == 0) {
    spdlog::error("Failed to start AssetManager: {}", IMG_GetError());
    throw runtime_error();
  }
}

/**
 * Quit an AssetManager instance.
 */
void AssetManager::quit() { IMG_Quit(); }