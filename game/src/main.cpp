
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL2_mixer/SDL_mixer.h>

#include "GameConfig.h"
#include "WindowEnvironment.h"

#include <string>
#include <iostream>
#include <cstdlib>
#include <filesystem>


using namespace std;



int main() {
  time_t s_time = time(NULL);


  filesystem::path cwd = filesystem::current_path() / "audio" / "aaa.mp3";
  cout << cwd;
  cout  << " Version " << VERSION_MAJOR << "."
        << VERSION_MINOR <<  "\n";
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  IMG_Init(IMG_INIT_PNG);
  TTF_Init();
  int result = Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 1024 );

// Check load
if ( result != 0 ) {
	cout << "Failed to open audio: " << Mix_GetError() << endl;
}



int MinSize = 0;
int MaxSize = 255;

SDL_Window* window = SDL_CreateWindow("potato",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE);
SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
SDL_DisplayMode DM;
SDL_GetCurrentDisplayMode(0, &DM);
auto MaxPosX = DM.w;
auto MaxPosY = DM.h;
int MinPos = 0;

  SDL_Rect* rect;
  SDL_Renderer* rend = SDL_CreateRenderer(window, -1, 0);
  SDL_Event e;
  bool quit = false;


  Mix_Chunk* music;

  music = Mix_LoadWAV( cwd.c_str() );
  if( !music  ) {
	cout << "Failed to load music or sound: " << Mix_GetError() << endl;
}



  cout << cwd;



  filesystem::path wwwww = filesystem::current_path() / "assets" / "prime_time.jpg";


SDL_Surface* surface = IMG_Load(wwwww.c_str()); 
SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, surface); 










  bool FULL_SCREEN = FULL_SCREEN_DEFAULT;
  while (!quit){
    time_t e_time = time(NULL);
          if (e_time - s_time > 60){
            quit = true;
            break;
          }
      while (SDL_PollEvent(&e)){
          SDL_PumpEvents();

          // update keyboard state
          Uint8* keysArray = const_cast <Uint8*> (SDL_GetKeyboardState(NULL));


          if (e.type == SDL_QUIT){
              quit = true;
          }
          if (e.type == SDL_KEYDOWN){


cout << Mix_PlayChannel(-1,  music, 2 );
              SDL_Delay(100);

 
            if (e.key.keysym.sym == SDLK_ESCAPE) {
              quit = true;
            }
          }
          if (e.type == SDL_KEYDOWN){
            if (e.key.keysym.sym == SDLK_f) {
              if(!FULL_SCREEN) {
                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
                FULL_SCREEN = !FULL_SCREEN;
                SDL_GetCurrentDisplayMode(0, &DM);
                auto MaxPosX = DM.w;
                auto MaxPosY = DM.h;
              } else {
                SDL_SetWindowFullscreen(window, 0);
                FULL_SCREEN = !FULL_SCREEN;
                SDL_GetCurrentDisplayMode(0, &DM);
                auto MaxPosX = DM.w;
                auto MaxPosY = DM.h;
            }
          }
        }

        while (
          // e.type == SDL_MOUSEBUTTONDOWN &&
          keysArray[SDL_SCANCODE_LSHIFT]
        ) {
            SDL_RenderClear(rend);



SDL_Rect dest;
dest.x = (rand() % (MaxPosX + 1 - MinPos) + MinPos) - 100; //e.motion.x;
dest.y = (rand() % (MaxPosY + 1 - MinPos) + MinPos) - 100; //e.motion.y;
dest.w = 10* (rand() % (MaxSize + 1 - MinSize) + MinSize);
dest.h = 10* (rand() % (MaxSize + 1 - MinSize) + MinSize);

SDL_RenderCopy(rend, texture, NULL, &dest);

            SDL_Rect rect;
            for (int i = 0; i<50; i++) {
            rect.x = rand() % (MaxPosX + 1 - MinPos) + MinPos; //e.motion.x;
            rect.y = rand() % (MaxPosY + 1 - MinPos) + MinPos; //e.motion.y;
            rect.w = rand() % (MaxSize + 1 - MinSize) + MinSize;
            rect.h = rand() % (MaxSize + 1 - MinSize) + MinSize;

            SDL_SetRenderDrawColor(rend, rand() % (255 + 1 - 0) + 0, rand() % (255 + 1 - 0) + 0, rand() % (255 + 1 - 0) + 0, 255);
            SDL_RenderFillRect(rend, &rect);
            }

            SDL_SetRenderDrawColor(rend, rand() % (255 + 1 - 0) + 0, rand() % (255 + 1 - 0) + 0, rand() % (255 + 1 - 0) + 0, 255);

            SDL_RenderPresent(rend);
            SDL_PumpEvents();
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

  Mix_FreeChunk( music );
    music = NULL;
  SDL_FreeSurface(surface);
  SDL_DestroyRenderer(rend);
  SDL_DestroyWindow(window);
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
  return 0;
}
