#include <Engine/Manager/Window.hpp>

#include <spdlog/spdlog.h>

// Initialise a WindowManager instance
void WindowManager::init() {
  // Initialise the window
  window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT,
                            SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_OPENGL |
                                SDL_WINDOW_SHOWN);
  if (window == NULL) {
    SPDLOG_ERROR(SDL_GetError());
  }
  // Initialise the renderer
  renderer = SDL_CreateRenderer(window, -1, 0);
  if (renderer == NULL) {
    SPDLOG_ERROR(SDL_GetError());
  }
}

// Quit a WindowManager instance
void WindowManager::quit() {
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}