#include <Engine/GameLoop/Utilities/FPSCounter.hpp>

void FPSCounter::startLoop() {
  if (frameCounter == frameRate) {
    frameCounter = 0;
    tickCounter = 0;
  }
  frameCounter++;
  tmpTicks = SDL_GetTicks();
};

void FPSCounter::endLoop() {
  float frameElapsedTime = (SDL_GetTicks() - tmpTicks) / 1000.0f;
  float targetElapsedTime = 1000.0f / frameRate;
  if (frameElapsedTime < targetElapsedTime) {
    SDL_Delay(targetElapsedTime - frameElapsedTime);
  }
  tickCounter += SDL_GetTicks() - tmpTicks;
};

float FPSCounter::fps() { return 1000.0f / (tickCounter / frameCounter); }
