#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include "GameConfig.h"

#include <string>
#include <iostream>

int main() {
  // report version
  std::cout << " Version " << VERSION_MAJOR << "."
            << VERSION_MINOR << "\n";
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
}