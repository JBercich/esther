#include <Engine/Engine.hpp>
#include <Engine/Game.hpp>

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
        game.run();
    };

    /**
     * Class instance post-constructor actions.
     */
    void Engine::init()
    {

    };

    /**
     * Class instance pre-deconstructor actions.
     */
    void Engine::quit()
    {

    };   
}