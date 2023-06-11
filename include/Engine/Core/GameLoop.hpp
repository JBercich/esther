#ifndef GAME_LOOP_H
#define GAME_LOOP_H

namespace Engine
{
    /**
     * GameLoop
     * --------
     * Responsible for controlling the main game logic abstraction and game loop model
     * of the game with input, update and render functions. Added utilities are used for
     * controlling execution and passing around game data at runtime.
     */
    class GameLoop 
    {
        private:
            bool running = true;

            void input();
            void update();
            void render(double interpolation);
        
        public:
            GameLoop(){};
            ~GameLoop(){};
            
            void start();
    };
}
#endif
