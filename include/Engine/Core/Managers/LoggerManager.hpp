/**
 * @brief           Logging management controls the use of `spdlog` to setup the loggers
 *                  and sinks with respective formatters and levels. Further control of
 *                  log levels is performed in the top-level `Logger.hpp` with macros.
 * 
 * @file            LoggerManager.hpp
 * @date            2023-06-12
 * @author          Josh Bercich (joshbercich@gmail.com)
 * @copyright       Copyright (c) 2023 Josh Bercich (joshbercich@gmail.com)
 */

#ifndef LOGGER_MANAGER_H
#define LOGGER_MANAGER_H

#include <Engine/Core/Managers/ResourceManager.hpp>

#include <spdlog/spdlog.h>

namespace Engine::Managers
{
    /**
     * LoggerManager instances are responsible for the initialisation and shutdown of
     * an `spdlog` environment with specific logger instances defined for the app
     * engine and application abstractions.
     */
    class LoggerManager : public ResourceManager
    {
        public:
            void initialise();
            // void shutdown();
    };
}

#endif
