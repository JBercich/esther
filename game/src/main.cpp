
// #include "GameConfig.h"
// #include "WindowEnvironment.h"

#include <string>
#include <iostream>

// #include <Engine/Window.h>

#include <CmakeConfig.hpp>
#include <Engine/GameEngine.hpp>

#include <spdlog/spdlog.h>

using namespace std;

int main()
{
  // Runtime logging setup
  spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");
  spdlog::enable_backtrace(20);
  
  // Runtime loop
  GameEngine gameEngine;
  gameEngine.init();
  SDL_Delay(3000);
  gameEngine.quit();

  // Application close 
  spdlog::dump_backtrace(); 

  // TTF_Init();

  // SDL_Event e;
  // while (!quit)
  // {
  //   while (SDL_PollEvent(&e))
  //   {
  //     if (!lshift)
  //     {
  //       if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LSHIFT)
  //       {
  //         lshift = true;
  //       }
  //     }
  //     if (lshift)
  //     {
  //       if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_LSHIFT)
  //       {
  //         lshift = false;
  //       }
  //     }
  //     if (e.type == SDL_QUIT)
  //     {
  //       quit = true;
  //     }
  //     if (e.type == SDL_KEYDOWN)
  //     {
  //       if (e.key.keysym.sym == SDLK_ESCAPE)
  //       {
  //         quit = true;
  //       }
  //     }

  //     if (e.type == SDL_KEYDOWN)
  //     {
  //       if (e.key.keysym.sym == SDLK_f)
  //       {
  //         if (!FULL_SCREEN)
  //         {
  //           SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
  //           FULL_SCREEN = !FULL_SCREEN;
  //         }
  //         else
  //         {
  //           SDL_SetWindowFullscreen(window, 0);
  //           FULL_SCREEN = !FULL_SCREEN;
  //         }
  //       }
  //     }
  //     if (e.type == SDL_MOUSEBUTTONDOWN && lshift)
  //     {
  //       SDL_RenderClear(rend);
  //       SDL_Rect rect;
  //       rect.x = e.motion.x;
  //       rect.y = e.motion.y;
  //       rect.w = 32;
  //       rect.h = 32;
  //       SDL_SetRenderDrawColor(rend, 255, 0, 255, 255);
  //       SDL_RenderFillRect(rend, &rect);
  //       SDL_SetRenderDrawColor(rend,
  //                              BACKGROUND_R,
  //                              BACKGROUND_G,
  //                              BACKGROUND_B,
  //                              BACKGROUND_A);
  //       SDL_RenderPresent(rend);
  //     }

  //     //

  //     // if (lshift && e.type == SDL_MOUSEBUTTONDOWN){
  //     //     SDL_RenderClear(rend);

  //     //     SDL_Circle circ;

  //     //     circ.x = e.motion.x;
  //     //     circ.y = e.motion.y;
  //     //     circ.r = 16;
  //     //     SDL_SetRenderDrawColor(rend, 255,0,255,255);
  //     //     SDL_RenderFillRect(rend, &circ);
  //     //     SDL_SetRenderDrawColor(rend,
  //     //                 BACKGROUND_R,
  //     //                 BACKGROUND_G,
  //     //                 BACKGROUND_B,
  //     //                 BACKGROUND_A);
  //     //     SDL_RenderPresent(rend);

  //     // }
  //     //
  //   }
  // }
}
