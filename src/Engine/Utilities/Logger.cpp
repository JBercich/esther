#include <Engine/Utilities/Logger.hpp>

#include <Build/BuildConfig.hpp>

#include <spdlog/spdlog.h>

#include <cassert>
#include <stdexcept>

namespace Engine
{
    void initLogger()
    {
        // Setup the log level based on the build type
        assert(CMAKE_BUILD_TYPE_FLAG == 0 || CMAKE_BUILD_TYPE_FLAG == 1);
        switch (CMAKE_BUILD_TYPE_FLAG)
        {
            case 1:
                spdlog::set_level(spdlog::level::debug);
                break;
            case 0:
                spdlog::set_level(spdlog::level::info);
                break;
            default:
                break;
        }

        // Setup the logger pattern
        spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e%z] [%n] [%^%L%$] [thread %t] %v");
        spdlog::debug("test");
        spdlog::debug("test");
        spdlog::critical("test");
        auto logger = spdlog::default_logger()->clone(LoggerMap[Logger::Engine]);
        logger->critical("test");
        spdlog::get(LoggerMap[Logger::Engine])->info("A");

    };
    void quitLogger(){};
}