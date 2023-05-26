#include <iostream>
#include <Engine/GameEngine.hpp>

int main(int, char **)
{
    std::cout << "Hello, world!\n";
}

// #include <SXSW/Game.hpp>
// #include <Engine/GameEngine.hpp>
// #include <iostream>
// #include <spdlog/spdlog.h>

// int main() {
//     // Runtime logging setup
//     // spdlog::set_pattern("[%H:%M:%S %z] [%^-%L-%$] [%s::%!(%#)] %v");
//     // spdlog::enable_backtrace(5);
//     // SPDLOG_INFO("starting game");

//     // // Runtime loop

//     GameEngine gameEngine;
//     Game game(60, gameEngine);
//     game.run();

//     // GameLoop gameLoop;
//     // gameLoop.gameEngine.init();
//     // gameLoop.run();
//     // gameLoop.gameEngine.quit();

//     // // Application close
//     // SPDLOG_INFO("starting game");
//     // spdlog::dump_backtrace();
//     // spdlog::shutdown();
//     return 1;

//     // SDL_Event e;
//     // while (!quit)
//     // {
//     //   while (SDL_PollEvent(&e))
//     //   {
//     //     if (!lshift)
//     //     {`
//     //       if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_LSHIFT)
//     //       {
//     //         lshift = true;
//     //       }
//     //     }
//     //     if (lshift)
//     //     {
//     //       if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_LSHIFT)
//     //       {
//     //         lshift = false;
//     //       }
//     //     }
//     //     if (e.type == SDL_QUIT)
//     //     {
//     //       quit = true;
//     //     }
//     //     if (e.type == SDL_KEYDOWN)
//     //     {
//     //       if (e.key.keysym.sym == SDLK_ESCAPE)
//     //       {
//     //         quit = true;
//     //       }
//     //     }

//     //     if (e.type == SDL_KEYDOWN)
//     //     {
//     //       if (e.key.keysym.sym == SDLK_f)
//     //       {
//     //         if (!FULL_SCREEN)
//     //         {
//     //           SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
//     //           FULL_SCREEN = !FULL_SCREEN;
//     //         }
//     //         else
//     //         {
//     //           SDL_SetWindowFullscreen(window, 0);
//     //           FULL_SCREEN = !FULL_SCREEN;
//     //         }
//     //       }
//     //     }
//     //     if (e.type == SDL_MOUSEBUTTONDOWN && lshift)
//     //     {
//     //       SDL_RenderClear(rend);
//     //       SDL_Rect rect;
//     //       rect.x = e.motion.x;
//     //       rect.y = e.motion.y;
//     //       rect.w = 32;
//     //       rect.h = 32;
//     //       SDL_SetRenderDrawColor(rend, 255, 0, 255, 255);
//     //       SDL_RenderFillRect(rend, &rect);
//     //       SDL_SetRenderDrawColor(rend,
//     //                              BACKGROUND_R,
//     //                              BACKGROUND_G,
//     //                              BACKGROUND_B,
//     //                              BACKGROUND_A);
//     //       SDL_RenderPresent(rend);
//     //     }

//     //     //

//     //     // if (lshift && e.type == SDL_MOUSEBUTTONDOWN){
//     //     //     SDL_RenderClear(rend);

//     //     //     SDL_Circle circ;

//     //     //     circ.x = e.motion.x;
//     //     //     circ.y = e.motion.y;
//     //     //     circ.r = 16;
//     //     //     SDL_SetRenderDrawColor(rend, 255,0,255,255);
//     //     //     SDL_RenderFillRect(rend, &circ);
//     //     //     SDL_SetRenderDrawColor(rend,
//     //     //                 BACKGROUND_R,
//     //     //                 BACKGROUND_G,
//     //     //                 BACKGROUND_B,
//     //     //                 BACKGROUND_A);
//     //     //     SDL_RenderPresent(rend);

//     //     // }
//     //     //
//     //   }
//     // }
// }
