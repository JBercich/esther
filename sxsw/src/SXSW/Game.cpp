#include <SXSW/Game.hpp>
#include <Engine/Utilities/FPSController.hpp>

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>
#include <ctime>

/**
 * Run the main game loop for the defined game. This will manage the FPS system for the
 * game object, handle inputs, update, and render the game objects. External systems for
 * the game are explicitly contained within the input(), update(), and render() methods.
 */
void Game::run()
{
    using namespace std::chrono;
    FPSController z;


    // Clocks for tracking system seconds and per iteration expected delays
    auto tickClock = steady_clock::now();
    auto frameClock = steady_clock::now();

    // Frame rate ratio for added milliseconds on each iteration
    const int64_t frameRateRatio = 1000 / frameRate;

    // Frame counters for tracking the exact and elapsed frame rates
    uint framesElapsedCount = 0;
    float framesElapsedSystem = 0.0f;

    // Tick counters measure before and after milliseconds to get elapsed FPS
    uint64_t tickCounter, tempCounter;
    tickCounter = tempCounter = 0;

    // Start clock timers with appropriate offset
    tickClock += seconds(1);
    frameClock += milliseconds(frameRateRatio);

    // Main game loop
    z.start();
    running = true;
	while(running) {
        z.iterate();

        // // Starting wall clock for calculating frame ticks
        // tempCounter = duration_cast<milliseconds>(
        //     system_clock::now().time_since_epoch()).count();

        // // Update for second intervals by resetting counters and output rates
        // if(frameClock > tickClock) 
        // {
        //     // Calculate system frames per second
        //     framesElapsedSystem = 1000 / (tickCounter / framesElapsedCount);
        //     // std::cout << "FPS (C): " << framesElapsedCount <<  std::endl;
        //     // std::cout << "FPS (S): " << framesElapsedSystem <<  std::endl;

        //     // Reset clock timers and update for next interval
        //     tickCounter = framesElapsedCount = 0;
        //     tickClock += seconds(1);
        // }

        // // Update frame counter and clock
        // framesElapsedCount++;
        // frameClock += milliseconds(frameRateRatio);
	
        // Main game logic component
        input();
        update();
        render();
        z.delay();
        
        // Delay for appropriate frame rate cap and updating tick counter
        // std::this_thread::sleep_until(frameClock);
        // tickCounter += duration_cast<milliseconds>(
        //     system_clock::now().time_since_epoch()).count() - tempCounter;
    }
};

void Game::input(){};

void Game::update(){};

void Game::render(){};
