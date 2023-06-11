#include <Engine/Engine.hpp>

#include <Engine/Game.hpp>
#include <Engine/Utilities/Logger.hpp>

#include <SDL2_image/SDL_image.h>

#include <iostream>
#include <cstdlib>

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
        initLogger();
        init();
        game.run();
        quit();
    };

    /**
     * Class instance post-constructor actions.
     */
    void Engine::init(){};


//         void AssetManager::init() {
//   int initResult = IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
//   if (initResult == 0) {
//     SPDLOG_ERROR(IMG_GetError());
//   }
// }


    /**
     * Class instance pre-deconstructor actions.
     */
    void Engine::quit(){};

}