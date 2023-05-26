#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <chrono> 


// // Maximum for a commercial monitor
// constexpr uint16_t MAXIMUM_FPS = 144;  

// // Seconds for measuring current FPS
// constexpr uint16_t T_ITERATE = 1;  

// // Delta constants for iterating FPS clocks
// constexpr std::chrono::duration<float> DELTA_DELAY { 1000 / MAXIMUM_FPS };
// constexpr std::chrono::duration<float> DELTA_ITERATE { T_ITERATE * 1000 };

// uint16_t frames = 0;            // Frame count over the tracked second
// uint64_t ticksIterate = 0;      // Tick count at the start of the tracked second
// uint64_t ticksPrevious = 0;     // Tick count at the previous frame

// // FPS clock controllers for performing updates
// std::chrono::time_point<std::chrono::steady_clock> A;
// std::chrono::time_point<std::chrono::steady_clock> B;
// std::chrono::time_point<std::chrono::steady_clock> C;

// using _steadyClock = std::chrono::steady_clock;
// using _timePoint = std::chrono::time_point<_steadyClock>;
// _timePoint frameClock = _steadyClock::now();    // Clock to track frame progress
// _timePoint iterateClock = _steadyClock::now();  // Clock to track fps second reset


/**
 * FPSController will track the progress of clocks and completed rendered frames for the
 * main game loop. I track the frames over the current iteration frame (over a second) 
 * which will give the current FPS - other measures are not required right now.
 */
class GameLoop {

    private:
    
    
    public:
        FPSController(){};
        ~FPSController(){};


        void update();
        void 
        void runGameLoop();
        void start();
        void iterate();
        void update();
        void delay();
};

#endif


/**
 * Game
 * State
 * Controller
 * 
 * 
 * 
 */