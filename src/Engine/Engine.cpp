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