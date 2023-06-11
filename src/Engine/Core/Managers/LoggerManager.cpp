#include <Engine/Core/Managers/LoggerManager.hpp>

#include <Engine/Logger.hpp>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

namespace Engine::Managers
{
    void LoggerManager::initialise()
    {
        // Setup logger sinks
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        consoleSink->set_pattern(DEFAULT_LOGGER_PATTERN);
        std::vector<spdlog::sink_ptr> sinks { consoleSink };

        // Setup the pooled loggers
        auto engineLogger = std::make_shared<spdlog::logger>(
            DEFAULT_LOGGER_ENGINE_NAME, sinks.begin(), sinks.end());
        auto gameLogger = std::make_shared<spdlog::logger>(
            DEFAULT_LOGGER_GAME_NAME, sinks.begin(), sinks.end());
        spdlog::register_logger(engineLogger);
        spdlog::register_logger(gameLogger);

        // Set base logging and flush levels at trace for both
        engineLogger->set_level(spdlog::level::trace);
        engineLogger->flush_on(spdlog::level::trace);
        gameLogger->set_level(spdlog::level::trace);
        gameLogger->flush_on(spdlog::level::trace);
    };

    void LoggerManager::shutdown()
    {
        spdlog::shutdown();
    };
}