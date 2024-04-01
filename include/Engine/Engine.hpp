/**
 * @brief           Main engine abstraction which is used to run an application. This
 *                  is used to initialise dependent resources as well as shutdown said
 *                  resources, and also run an application.
 * 
 * @file            Engine.hpp
 * @date            2023-06-13
 * @author          Josh Bercich (joshbercich@gmail.com)
 * @copyright       Copyright (c) 2023 Josh Bercich (joshbercich@gmail.com)
 */

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
             */
            void initialise();

            /**
             * Shutdown all initialised resources in reverse order. This will catch all
             * performed shutdown operations to ensure that if shutdown is called at a
             * point between initialisation of certain resources, this will still exit.
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
