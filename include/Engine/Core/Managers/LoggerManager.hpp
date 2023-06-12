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

#include <spdlog/spdlog.h>

namespace Engine::Managers
{
    /**
     * LoggerManager instances are responsible for the initialisation and shutdown of
     * an `spdlog` environment with specific logger instances defined for the app
     * engine and game abstractions.
     */
    class LoggerManager 
    {
        public:
            LoggerManager() = default;
            ~LoggerManager() = default;

            /**
             * Initialise the LoggerManager instance by creating the logging sinks and
             * separate loggers for the engine and game environments. Logger output
             * patterns and (flush) levels are set respectively.
             */
            void initialise();

            /**
             * Loggers from `spdlog` are closed and deallocated.
             */
            void shutdown();
    };
}

#endif
