#ifndef ENGINE_H
#define ENGINE_H

#include <Engine/Game.hpp>

namespace Engine
{
    class Engine 
    {
        private:
            void init();
            void quit();
        public:
            void run(Game game);
    };
}

#endif
