#include <Engine/GameLoop.hpp>
#include <spdlog/spdlog.h>

#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <string>
#include <functional>
#include <any>

using namespace std;

void GameLoop::controller(){};

void GameLoop::update(){};

void GameLoop::draw(){};


map<int, bool> keys_on; // keys acting like a switch
map<int, function<void()>> key_action; // key-function map

// Function to map a given function to a specific key press
void give_action(int key, function<void()> func) {
  key_action[key] = func;
}

// Define functions to be excuted when a specific key is pressed
bool first = true;
bool t_alt = false;
bool do_action = false;

void press_a() {
  cout << "you pressed a" << "\n";
}

// supposed to swap between true and false
void press_t() { 
  if (first) {
    t_alt = true;
    first = false;
  }
  else {
    t_alt = !t_alt; 
  }
  cout << "you made t = " << t_alt << "\n";
}

void press_esc() {
  cout << "\n" << "you quit the game" << "\n" << "\n";
  GameLoop gameLoop;
  gameLoop.gameEngine.quit();
}

SDL_Event event;

void GameLoop::run() {
  // Give actions to keys
  give_action(SDLK_a, press_a); // must be in GameLoop
  give_action(SDLK_t, press_t);
  give_action(SDLK_ESCAPE, press_esc);
  
  Uint32 totalFrameTicks = 0;
  Uint32 totalFrames = 0;
  while (totalFrameTicks < 10000) {

    totalFrames++;
    Uint32 startTicks = SDL_GetTicks();
    Uint64 startPerf = SDL_GetPerformanceCounter();

    SDL_Delay(rand() % 25);

    if (SDL_PollEvent(&event)){
      if (event.type == SDL_KEYDOWN) {
        if (keys_on.find(event.key.keysym.sym) == keys_on.end()) {
          keys_on[event.key.keysym.sym] = true;
          do_action = true; //to prevent repeated action execution during button hold
        }
        else if (keys_on[event.key.keysym.sym] == false) {
          keys_on[event.key.keysym.sym] = true;
          do_action = true; //to prevent repeated action execution during button hold
        }
      }
      else if (event.type == SDL_KEYUP) {
        if (keys_on[event.key.keysym.sym] == true) {
          keys_on[event.key.keysym.sym] = false;
        }
      }
      /* // switch(event.type){
      //   case SDL_KEYDOWN:
      //     keys_on[event.key.keysym.sym] = true;
      //       break;
      //   case SDL_KEYUP:
      //     keys_on[event.key.keysym.sym] = false;
      //       break;
      // } */
    }
    if (do_action && key_action.find(event.key.keysym.sym) == key_action.end() && event.type == SDL_KEYDOWN) {
      cout << "no function" << "\n"; // Only runs when first press button
    }
    else if (do_action && keys_on[event.key.keysym.sym] == true) {
      key_action[event.key.keysym.sym](); // Repeats each loop while holding down button
    }
    do_action = false; //to prevent repeated action execution during button hold

    // End frame timing
    Uint32 endTicks = SDL_GetTicks();
    Uint64 endPerf = SDL_GetPerformanceCounter();
    Uint64 framePerf = endPerf - startPerf;
    float frameTime = (endTicks - startTicks) / 1000.0f;
    totalFrameTicks += endTicks - startTicks;

    // Strings to display
    string fps = "Current FPS: " + to_string(1.0f / frameTime);
    string avg = "Average FPS: " +
                 to_string(1000.0f / ((float)totalFrameTicks / totalFrames));
    string perf = "Current Perf: " + to_string(framePerf);

    // std::cout << avg << "\n";
    
  }
};
