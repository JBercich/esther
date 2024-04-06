#include <Engine/Core/Managers/LoggerManager.hpp>
#include <Engine/Logger.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

namespace Engine::Managers
{
    void LoggerManager::initialise()
    {
        // Setup logger sinks (coloured stdout)
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        consoleSink->set_pattern(DEFAULT_LOGGER_PATTERN);
        std::vector<spdlog::sink_ptr> sinks { consoleSink };
        // Setup the pooled loggers (combine game and engine loggers)
        auto engLogger = std::make_shared<spdlog::logger>(
            DEFAULT_LOGGER_ENG_NAME, sinks.begin(), sinks.end());
        auto runLogger = std::make_shared<spdlog::logger>(
            DEFAULT_LOGGER_RUN_NAME, sinks.begin(), sinks.end());
        spdlog::register_logger(engLogger);
        spdlog::register_logger(runLogger);
        // Set base logging and flush levels at trace for both
        engLogger->set_level(spdlog::level::trace);
        engLogger->flush_on(spdlog::level::trace);
        runLogger->set_level(spdlog::level::trace);
        runLogger->flush_on(spdlog::level::trace);
    };

    void LoggerManager::shutdown()
    {
        spdlog::shutdown();
    };
}