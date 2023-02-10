#include <Engine/GameLoop.hpp>

#include <iostream>

void GameLoop::controller(){};

void GameLoop::update(){};

void GameLoop::draw(){};

void GameLoop::run() {

  Uint32 totalFrameTicks = 0;
  Uint32 totalFrames = 0;
  while (totalFrameTicks < 10000) {

    totalFrames++;
    Uint32 startTicks = SDL_GetTicks();
    Uint64 startPerf = SDL_GetPerformanceCounter();

    SDL_Delay(rand() % 25);

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

    std::cout << avg << "\n";
  }
};
