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
            void shutdown();
    };
}

#endif
