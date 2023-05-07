#ifndef FPS_COUNTER_HPP
#define FPS_COUNTER_HPP

#include <SDL2/SDL.h>

#define FPS_COUNTER_DEFAULT_FRAME_RATE 60

class FPSCounter {
public:
  Uint32 frameRate = FPS_COUNTER_DEFAULT_FRAME_RATE;
  Uint32 frameCounter = 0;
  Uint32 tickCounter = 0;
  Uint32 tmpTicks = 0;
  void startLoop();
  void endLoop();
  float fps();
};

#endif
