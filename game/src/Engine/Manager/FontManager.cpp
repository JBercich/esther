#include <Engine/Manager/FontManager.hpp>

#include <SDL2_ttf/SDL_ttf.h>
#include <spdlog/spdlog.h>

// Initialise an AssetManager instance
void FontManager::init() {
  int initResult = TTF_Init();
  if (initResult == -1) {
    SPDLOG_ERROR(TTF_GetError());
  }
}

// Quit an AssetManager instance
void FontManager::quit() { TTF_Quit(); }