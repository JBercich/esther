#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

// #include "GameConfig.h"
// #include "WindowEnvironment.h"

// #include <string>
// #include <iostream>

// #include <Engine/Window.h>

#include <Engine/WindowManager.hpp>
using namespace std;

int main()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  WindowManager windowManager;
  windowManager.init();
  SDL_Delay(3000);
  windowManager.quit();

  SDL_Quit();
  //  cout << n.window << endl;
  //  return 0;
  // cout << &w;

  // // report version
  // cout << " Version " << VERSION_MAJOR << "."
  //      << VERSION_MINOR << "\n";
  // SDL_Init(SDL_INIT_VIDEO);
  // IMG_Init(IMG_INIT_PNG);
  // TTF_Init();

  // SDL_Window *window = SDL_CreateWindow("potato",
  //                                       SDL_WINDOWPOS_CENTERED,
  //                                       SDL_WINDOWPOS_CENTERED,
  //                                       WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);

  // SDL_Renderer *rend = SDL_CreateRenderer(window, -1, 0);
  // SDL_Event e;
  // bool quit = false;
  // bool FULL_SCREEN = FULL_SCREEN_DEFAULT;
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

  // /* Release resources */
  // SDL_DestroyRenderer(rend);
  // SDL_DestroyWindow(window);
  // SDL_Quit();
  // return 0;
}
