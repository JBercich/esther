#include <Engine/AssetManager.hpp>

#include <SDL2_Image/SDL_Image.h>
#include <spdlog/spdlog.h>

// Initialise an AssetManager instance
void AssetManager::init() {
  int initResult = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
  if (initResult == 0) {
    SPDLOG_ERROR(IMG_GetError());
  }
}

// Quit an AssetManager instance
void AssetManager::quit() { IMG_Quit(); }