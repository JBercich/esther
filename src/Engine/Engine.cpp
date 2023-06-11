#include <Engine/Engine.hpp>

#include <Engine/Game.hpp>
#include <Engine/Logger.hpp>
#include <Engine/Core/Managers/LoggerManager.hpp>

#include <SDL2_image/SDL_image.h>

#include <iostream>
#include <cstdlib>
#include <spdlog/spdlog.h>

namespace Engine 
{

    /**
     * Game engine running sequence. This should perform essential actions for starting
     * the runtime environment of a game. This will prepare everything up to the start
     * screen of the game, and will gracefully handle any errors the game encounters.
     * 
     * @param game          Game object containing a game loop to run.
     */
    void Engine::run(Game game)
    {
        std::cout << "tttt" <<std::endl;
        init();
        std::cout << "tttt" <<std::endl;
        game.run();
        quit();
    };

    void Engine::init()
    {
        loggerManager.initialise();
        ENGINE_TRACE("Test {}", 1);
    };

    void Engine::quit()
    {
        loggerManager.shutdown();
    };

}