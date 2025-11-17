#include <Engine/Engine.hpp>
#include <Engine/Logger.hpp>

namespace Engine 
{
    void Engine::initialise()
    {
        // Initialise logger manager
        loggerManager.initialise();
        ENGINE_INFO("Initialised loggerManager instance");
    };

    void Engine::shutdown()
    {
        // Shutdown logger manager
        ENGINE_INFO("Shutdown loggerManager instance");
        loggerManager.shutdown();
    }

    void Engine::run(Game game)
    {
        game.run();
    };
}