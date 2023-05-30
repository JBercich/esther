#ifndef GAME_LOOP_H
#define GAME_LOOP_H

class GameLoop 
{
    private:
        bool running { false };
    
    public:
        GameLoop(){};
        ~GameLoop(){};

        void start();

        void input();
        void update();
        void render();
};

#endif
