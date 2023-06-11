#include <Engine/Game.hpp>
#include <Engine/Core/GameLoop.hpp>
#include <iostream>
namespace Engine
{
    /**
     * Running body for a game to execute. This will accumulate the many game data 
     * structures so that performing necessary game loop functions is efficient and 
     * simple to implement.
     */
    void Game::run()
    {
        GameLoop loop;
        loop.start();
    };
}