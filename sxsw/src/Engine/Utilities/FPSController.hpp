#ifndef FPS_CONTROLLER_H
#define FPS_CONTROLLER_H

#include <chrono> 

/**
 * FPS controller is upper bounded by a static 144 Hz which aligns with most commercial
 * monitors for playing video games. There should be no impact of a larger FPS for lower
 * refresh rate displays. Fine grained static FPS control is defined and so constants
 * below are defined for any application in general with no forseen impact.
 */

// Maximum for a commercial monitor
constexpr uint16_t MAXIMUM_FPS = 144;  

// Seconds for measuring current FPS
constexpr uint16_t T_ITERATE = 1;  

// Delta constants for iterating FPS clocks
constexpr std::chrono::milliseconds DELTA_DELAY { 1000 / MAXIMUM_FPS };
constexpr std::chrono::milliseconds DELTA_ITERATE { T_ITERATE * 1000 };

/**
 * FPSController will track the progress of clocks and completed rendered frames for the
 * main game loop. I track the frames over the current iteration frame (over a second) 
 * which will give the current FPS - other measures are not required right now.
 */
class FPSController {

    private:
        uint16_t frames = 0;            // Frame count over the tracked second
        uint64_t ticksIterate = 0;      // Tick count at the start of the tracked second
        uint64_t ticksPrevious = 0;     // Tick count at the previous frame

        // FPS clock controllers for performing updates
        using _steadyClock = std::chrono::steady_clock;
        using _timePoint = std::chrono::time_point<_steadyClock>;
        _timePoint frameClock = _steadyClock::now();    // Clock to track frame progress
        _timePoint iterateClock = _steadyClock::now();  // Clock to track fps second reset

    public:
        FPSController(){};
        ~FPSController(){};

        const uint16_t fps();

        void start();
        void iterate();
        void update();
        void delay();
};

#endif