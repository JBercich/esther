#ifndef ENGINE_H
#define ENGINE_H

#include <Engine/Game.hpp>

namespace Engine
{
    /**
     * Engine
     * ------
     * Top-level abstraction of the game engine which contains the main entry-points of
     * any game execution procedure. This will support running a game with a very simple
     * set of instructions for a complete runtime.
     * 
     *      Engine::Game game;
     *      Engine::Engine engine;
     *      engine.run(game);
     * 
     * All initialisation and 
     * 
     */
    class Engine 
    {
        private:
            void init();
            void quit();
            
        public:
            Engine(){};
            ~Engine(){};

            void run(Game game);
    };
}

#endif
