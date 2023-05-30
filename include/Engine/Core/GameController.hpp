#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include <chrono>

constexpr uint16_t MAX_FRAMES_PER_SECONDS { 144 };
constexpr float MAX_SINGLE_FRAME_TICKS { 1000 / MAX_FRAMES_PER_SECONDS };

constexpr uint16_t MAX_SINGLE_FRAME_UPDATES { 10 };

constexpr std::chrono::duration<float> DELTA_S { 1000 };
constexpr std::chrono::duration<float> DELTA_FRAME { 1000 / MAX_SINGLE_FRAME_TICKS };
constexpr std::chrono::duration<float> DELTA_UPDATE { 500 / MAX_SINGLE_FRAME_TICKS };

class GameController 
{
    private:
        uint16_t frames { 0 };
        uint64_t endTicks { 0 };
        uint64_t startTicks { 0 };
        uint64_t previousTicks { 0 };

        std::chrono::duration<float> lag { 0 };
        std::chrono::duration<float> frameElapsed { 0 };

        std::chrono::time_point<std::chrono::steady_clock> frameStart { 
            std::chrono::steady_clock::now()};
        std::chrono::time_point<std::chrono::steady_clock> framePrevious { 
            std::chrono::steady_clock::now()};

        std::chrono::time_point<std::chrono::steady_clock> frameDelay { 
            std::chrono::steady_clock::now()};


    
    public:
        GameController(){};
        ~GameController(){};

        void step();
        void update();
        bool canUpdate();
};

#endif
