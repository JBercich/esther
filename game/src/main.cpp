#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "GameConfig.h"

#include <string>
#include <iostream>


using namespace std;


int main() {
  // report version
  cout  << " Version " << VERSION_MAJOR << "."
        << VERSION_MINOR <<  "\n";
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();




  SDL_Window* window = SDL_CreateWindow("potato",
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      256, 256, 0);


  
  SDL_Renderer* rend = SDL_CreateRenderer(window, -1, 0);
  SDL_Event e;
  bool quit = false;
  while (!quit){
      while (SDL_PollEvent(&e)){
          if (e.type == SDL_QUIT){
              quit = true;
          }
          if (e.type == SDL_KEYDOWN){
              quit = true;
          }
          if (e.type == SDL_MOUSEBUTTONDOWN){
              quit = true;
          }
      }
  }

  /* Release resources */
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}


