#include <Engine/Core/GameController.hpp>

#include <chrono>
#include <thread>
#include <algorithm>

namespace Engine
{
    /**
     * Step function for the game controller executed at the start of ever game loop 
     * iteration. This will update the appropriate control measures for serialising the
     * frame rate of the game. Additional delays are implemented to restrict excessive
     * refresh rates without vsync and second-interval updates of the FPS are done.
     */
    void GameController::step()
    {   
        // Catch vsync issues by sleeping when reaching too high an FPS
        std::this_thread::sleep_until(frameTimer);

        // Step forward in the game controller
        startLoopTime = std::chrono::steady_clock::now();
        gameTime += (startLoopTime - previousLoopTime).count() * 1000;
        previousLoopTime = startLoopTime;
        updateCounter = 0;

        // Check if a second has passed
        if(std::chrono::steady_clock::now() >= secondTimer)
        {
            // Calculate the FPS and tick rates and reset counters
            fps = (startLoopTime - previousSecondTime).count() * frameCounter;
            tickRate = (startLoopTime - previousSecondTime).count() * updateCounterT;
            frameCounter = 0;
            updateCounterT = 0;

            // Update time measures for the controller and instantiate for first loop
            previousSecondTime = startLoopTime;
            secondTimer = std::chrono::steady_clock::now() + std::chrono::seconds(1);
            frameTimer = std::chrono::steady_clock::now();
        }

        // Update frame timer and counter
        frameTimer += DELTA_FPS;
        frameCounter++;
    };

    void GameController::update()
    {
        gameTime -= DELTA_TICK_RATE.count();
        updateCounter++;
        updateCounterT++;
    };

    /**
     * Indicate if the inner update loop can be run.
     * 
     * @return true         Update inner loop can be executed if the number of updates
     *                      for the current frame render is below the max threshold and 
     *                      the simulated game time is behind the render rate.
     * @return false        Otherwise.
     */
    bool GameController::canUpdate()
    {
        return updateCounter < GAME_SPEED_UPDATE_LIMIT && gameTime > 0;
    };

    /**
     * Calculate the frame interpolation when there is delay within the game loop and a
     * mismatch between rendering rates of fixed steps updates.
     * 
     * @return double       Interpolation of the rendered frame.
     */
    double GameController::getInterpolation()
    {
        return std::max({0.0, gameTime / DELTA_TICK_RATE.count()});
    };
}
