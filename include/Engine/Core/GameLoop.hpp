#ifndef GAME_LOOP_H
#define GAME_LOOP_H

namespace Engine
{
    /**
     * GameLoop
     * --------
     * The game loop is the main executing block of the game logic. This will contain 
     * the generalised input, update and render functions which will accept overridable
     * input data structures for easy exportable functionality. The loop itself is
     * controlled with a fine granularity as supported by a GameController instance.
     * 
     *      GameLoop loop;
     *      loop.start();
     */
    class GameLoop 
    {
        private:
            bool running { true };

            void input();
            void update();
            void render();
        
        public:
            GameLoop(){};
            ~GameLoop(){};
            
            void start();
    };
}
#endif
