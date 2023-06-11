
#ifndef LOGGER_MANAGER_H
#define LOGGER_MANAGER_H

#include <spdlog/spdlog.h>

namespace Engine::Managers
{
    class LoggerManager 
    {
        public:
            LoggerManager() = default;
            ~LoggerManager() = default;
            void initialise();
            void shutdown();
    };
}

#endif
