#ifndef GAME_H
#define GAME_H

namespace Engine 
{
    /**
     * Game
     * ----
     * A game abstraction is a top-level representation of the running game. This engine
     * will perform some running sequence of the game without any direct game logic such
     * as controlling runtime flow of the FPS, and other static features of the game.
     * 
     *      Game game;
     *      game.run();
     * 
     * Running the game initialises the generic game loop while other abstractions are
     * responsible for containing the game logic and features themselves.
     */
    class Game 
    {
        private:

        public:
            Game(){};
            ~Game(){};
            
            void run();
    };
}

#endif
