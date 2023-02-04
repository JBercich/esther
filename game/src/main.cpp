#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "GameConfig.h"
#include "WindowEnvironment.h"

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


int Min = 0;
int Max = 255;

  SDL_Window* window = SDL_CreateWindow("potato",
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

  
  SDL_Rect* rect;
  SDL_Renderer* rend = SDL_CreateRenderer(window, -1, 0);
  SDL_Event e;
  bool quit = false;


  bool FULL_SCREEN = FULL_SCREEN_DEFAULT;
  while (!quit){
      while (SDL_PollEvent(&e)){
          SDL_PumpEvents();

          // update keyboard state
          Uint8* keysArray = const_cast <Uint8*> (SDL_GetKeyboardState(NULL));


          if (e.type == SDL_QUIT){
              quit = true;
          }
          if (e.type == SDL_KEYDOWN){
            if (e.key.keysym.sym == SDLK_ESCAPE) {
              quit = true;
            }
          }
          if (e.type == SDL_KEYDOWN){
            if (e.key.keysym.sym == SDLK_f) {
              if(!FULL_SCREEN) {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                FULL_SCREEN = !FULL_SCREEN;
              } else {
                SDL_SetWindowFullscreen(window, 0);
                FULL_SCREEN = !FULL_SCREEN;
            }
          }
        }

        if (
          e.type == SDL_MOUSEBUTTONDOWN && 
          keysArray[SDL_SCANCODE_LSHIFT]
        ) {
            SDL_RenderClear(rend);

            SDL_Rect rect;
            rect.x = e.motion.x;
            rect.y = e.motion.y;
            rect.w = std::rand() % (Max + 1 - Min) + Min;
            rect.h = std::rand() % (Max + 1 - Min) + Min;

            SDL_SetRenderDrawColor(rend, std::rand() % (Max + 1 - Min) + Min, std::rand() % (Max + 1 - Min) + Min, std::rand() % (Max + 1 - Min) + Min, 255);
            SDL_RenderFillRect(rend, &rect);

            SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

            SDL_RenderPresent(rend);
          }

          if (
            e.type == SDL_MOUSEBUTTONDOWN && 
            !keysArray[SDL_SCANCODE_LSHIFT]
          ) {
            
            SDL_RenderClear(rend);

            SDL_Rect rect;
            rect.x = e.motion.x;
            rect.y = e.motion.y;
            rect.w = 200;
            rect.h = 200;

            SDL_SetRenderDrawColor(rend, 255, 1, 255, 255);
            SDL_RenderFillRect(rend, &rect);

            SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);

            SDL_RenderPresent(rend);
          }
      }
  }

  /* Release resources */
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}


