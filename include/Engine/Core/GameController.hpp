#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <chrono>

namespace Engine 
{
    /**
     * A variable FPS is the product of the implemented deWitter loop although in the
     * event vsync errors exist at runtime, an upper bound is placed on the FPS so that
     * frames are delayed to prohibit excessive FPS rates.
     */
    constexpr double FPS = 600;
    constexpr double FPS_TICKS = 1000 / FPS;
    constexpr std::chrono::duration<double, std::milli> DELTA_FPS { FPS_TICKS };

    /**
     * Game speed and tick rate are used to explain the number of updates per second and
     * corresponding tick rate for the measure in milliseconds. This is a static value
     * as each update is of fixed length.
     */
    constexpr double GAME_SPEED = 50;
    constexpr double TICK_RATE = 1000 / GAME_SPEED;
    constexpr std::chrono::duration<double, std::milli> DELTA_TICK_RATE { TICK_RATE };

    /**
     * For the inner loop repeating the fixed-length update intervals, an upper-bound
     * number of updates is permitted so that a player is not stuck in an infinite loop.
     */
    constexpr uint16_t GAME_SPEED_UPDATE_LIMIT = 5;

    /**
     * GameController
     * --------------
     * Responsible for controlling the execution of the main game loop of a game. The
     * implementation is based on a deWitter game loop with variable FPS rendering and
     * fixed-length delta timesteps with render interpolation. This gives one of the 
     * most competitively relevant game loop in the industry.
     * 
     *      GameController controller;
     *      while (running)
     *      {
     *          controller.step();
     *          while(controller.canUpdate())
     *          {
     *              < Game update logic >
     *              controller.update();
     *          }
     *          < Render with controller.getInterpolation() >
     *      }
     */
    class GameController 
    {
        private:
            // Frame rate metrics
            double fps = 0;
            double frameCounter = 0;

            // Tick rate metrics
            double tickRate = 0;
            double updateCounter = 0; 
            double updateCounterT = 0; 

            // Tick counter for the simulated game time
            double gameTime = 0;

            // Iteration time points for frame rate and second-reset metrics
            std::chrono::time_point<std::chrono::steady_clock, 
                std::chrono::duration<double>> startLoopTime{};
            std::chrono::time_point<std::chrono::steady_clock, 
                std::chrono::duration<double>> previousLoopTime{};
            std::chrono::time_point<std::chrono::steady_clock, 
                std::chrono::duration<double>> previousSecondTime{};

            // Timers for the frame and second-reset intervals
            std::chrono::time_point<std::chrono::steady_clock, 
                std::chrono::duration<double>> frameTimer{};
            std::chrono::time_point<std::chrono::steady_clock, 
                std::chrono::duration<double>> secondTimer{};

        public:
            GameController() : 
                startLoopTime(std::chrono::steady_clock::now()),
                previousLoopTime(std::chrono::steady_clock::now()),
                previousSecondTime(std::chrono::steady_clock::now()){};
            ~GameController(){};

            void step();
            void update();
            bool canUpdate();
            double getInterpolation();
    };
}

#endif
