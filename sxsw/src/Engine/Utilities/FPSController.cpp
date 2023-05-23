#include <Engine/Utilities/FPSController.hpp>

#include <cmath>
#include <chrono>
#include <thread>
#include <SDL2/SDL.h>

#include <iostream>
#include <string>

using namespace std::chrono;

/**
 * Calculate the current FPS from the iteration.
 * 
 * @return    const uint16_t FPS from the iteration.
 */
const uint16_t FPSController::fps()
{
    // Get the current ticks and find the FPS
    uint64_t ticksCurrent = duration_cast<milliseconds>(
        system_clock::now().time_since_epoch()).count();
    return floor(1000 / (ticksCurrent - ticksIterate) / frames); 
};



    // // Alias a method to get ticks
    // using _durationCast = std::chrono::duration_cast<std::chrono::milliseconds>;
    // using _systemClock = std::chrono::system_clock;
    // auto _getTicks() { return _durationCast(_systemClock::now().time_since_epoch()).count(); };
    


// void FPSController::iterate()
// {
//     // // Starting wall clock for calculating frame ticks
//     // tempCounter = duration_cast<milliseconds>(
//     //     system_clock::now().time_since_epoch()).count();

//     // // Update for second intervals by resetting counters and output rates
//     // if(frameClock > tickClock) 
//     // {
//     //     // Calculate system frames per second
//     //     framesElapsedSystem = 1000 / (tickCounter / framesElapsedCount);
//     //     std::cout << "FPS (C): " << framesElapsedCount <<  std::endl;
//     //     std::cout << "FPS (S): " << framesElapsedSystem <<  std::endl;

//     //     // Reset clock timers and update for next interval
//     //     tickCounter = framesElapsedCount = 0;
//     //     tickClock += seconds(1);
//     // }

//     // // Update frame counter and clock
//     // framesElapsedCount++;
//     // frameClock += milliseconds(frameRateRatio);
// };


// 	while(running) {

//         // Starting wall clock for calculating frame ticks
//         tempCounter = duration_cast<milliseconds>(
//             system_clock::now().time_since_epoch()).count();

//         // Update for second intervals by resetting counters and output rates
//         if(frameClock > tickClock) 
//         {
//             // Calculate system frames per second
//             framesElapsedSystem = 1000 / (tickCounter / framesElapsedCount);
//             std::cout << "FPS (C): " << framesElapsedCount <<  std::endl;
//             std::cout << "FPS (S): " << framesElapsedSystem <<  std::endl;

//             // Reset clock timers and update for next interval
//             tickCounter = framesElapsedCount = 0;
//             tickClock += seconds(1);
//         }

//         // Update frame counter and clock
//         framesElapsedCount++;
//         frameClock += milliseconds(frameRateRatio);
	
//         // Main game logic component
//         input();
//         update();
//         render();
        
//         // Delay for appropriate frame rate cap and updating tick counter
//         std::this_thread::sleep_until(frameClock);
//         tickCounter += duration_cast<milliseconds>(
//             system_clock::now().time_since_epoch()).count() - tempCounter;
//     }
// };


/**
 * Set the Fps object.
 * 
 * @param fps           Frames per second.
 */
// void FPSController::setFps(uint16_t fps)
// {
//     assert(fps > 0 && "FPS must be greater than 0");
//     assert(fps <= MAX_FPS && "FPS must be less than MAX_FPS");
//     this->fps = fps;
//     // this->tps = 1000 / fps;
// };

/**
 * Start the FPS controller prior to executing the game loop to initialise the first
 * clock delta steps. This should be executed immediately before the game loop to get
 * accurate FPS measurements.
 */
void FPSController::start()
{   
    // Start each clocks at the appropriate offset
    frameClock += DELTA_DELAY;
    iterateClock += DELTA_ITERATE;
};

/**
 * Called at the start of each iteration this function will check if a second has passed
 * to reset any FPS counters and clocks.
 */
void FPSController::iterate()
{
    if(frameClock >= iterateClock)
    {
        // Calculate the current FPS
        const uint16_t currentFps = fps();

        // Reset counters and update clock
        frames = 0;
        ticksIterate = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        iterateClock += DELTA_ITERATE;

        // Print FPS
        std::cout << "FPS: " << currentFps << std::endl;
    }
    // std::cout << "FPS: " << frameClock.time_since_epoch().count() - iterateClock.time_since_epoch().count() << std::endl;
    // std::cout << "FPS: " << iterateClock.time_since_epoch().count() << std::endl;
    // Increment counters and clock
    frames++;
    frameClock += DELTA_DELAY;
};

void update()
{

};

void FPSController::delay()
{
    std::this_thread::sleep_until(frameClock);
};
