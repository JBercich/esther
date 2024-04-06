#ifndef ENGINE_H
#define ENGINE_H

#include <Engine/Game.hpp>
#include <Engine/Core/Managers/LoggerManager.hpp>


namespace Engine
{
    class Engine 
    {
        private:
            Managers::LoggerManager loggerManager;
            
        public:
            Engine(){};
            ~Engine(){};

            /**
             * Initialise all required resources for the engine. This will take any
             * resource managers and initialise them in the required order and report on
             * the functionality of said resources.
             * 
             * @example             >>> engine.logger.initialise();
             *                      >>> engine.logger.info("Initialised engine");
             */
            void initialise();

            /**
             * Shutdown all initialised resources in reverse order. This will catch all
             * performed shutdown operations to ensure that if shutdown is called at a
             * point between initialisation of certain resources, this will still exit.
             * 
             * @example             >>> engine.logger.info("Shutting down engine");
             *                      >>> engine.logger.shutdown();
             * 
            */
            void shutdown();

            /**
             * Run a given application for the engine. This will take a game input which
             * can be run within a game loop controlled by this run function.
             * 
             * @param game          Game instance that interacts with the game engine
             *                      for evolving runtime logic.
             */
            void run(Game game);
    };
}

#endif
