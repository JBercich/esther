/**
 * @file Logger.hpp
 * @brief Logging utility wrapper for spdlog
 * 
 * This file provides a convenient logging interface for the game engine.
 * It wraps spdlog functionality and provides easy-to-use macros for logging
 * at different levels throughout the application.
 * 
 * Usage:
 *   LOG_INFO("Application started");
 *   LOG_ERROR("Failed to load texture: {}", filename);
 *   LOG_DEBUG("Frame time: {:.2f}ms", deltaTime * 1000.0f);
 */

#ifndef ESTHER_LOGGER_HPP
#define ESTHER_LOGGER_HPP

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>
#include <string>

namespace Esther {
namespace Core {

/**
 * @class Logger
 * @brief Manages application-wide logging configuration
 * 
 * This class initializes and configures spdlog for use throughout the engine.
 * It sets up both console and file logging with appropriate formatting and
 * log levels based on the build configuration.
 */
class Logger {
public:
    /**
     * @brief Initialize the logging system
     * 
     * Sets up spdlog with console and file sinks, configures log levels,
     * and establishes the log message format.
     * 
     * @param logFile Path to the log file (default: "esther.log")
     */
    static void init(const std::string& logFile = "esther.log") {
        try {
            // Create console sink with color support
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            console_sink->set_level(spdlog::level::trace);
            
            // Create file sink
            auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logFile, true);
            file_sink->set_level(spdlog::level::trace);
            
            // Combine sinks into a single logger
            std::vector<spdlog::sink_ptr> sinks {console_sink, file_sink};
            auto logger = std::make_shared<spdlog::logger>("esther", sinks.begin(), sinks.end());
            
            // Set the global logger
            spdlog::set_default_logger(logger);
            
            // Set log pattern: [timestamp] [level] [file:line] message
            spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%s:%#] %v");
            
            // Set log level based on build type
            #ifdef NDEBUG
                spdlog::set_level(spdlog::level::info);
            #else
                spdlog::set_level(spdlog::level::debug);
            #endif
            
            spdlog::info("Logger initialized successfully");
        }
        catch (const spdlog::spdlog_ex& ex) {
            fprintf(stderr, "Log initialization failed: %s\n", ex.what());
        }
    }
    
    /**
     * @brief Set the logging level
     * @param level The spdlog log level to set
     */
    static void setLevel(spdlog::level::level_enum level) {
        spdlog::set_level(level);
    }
    
    /**
     * @brief Shutdown the logging system
     * 
     * Flushes all pending log messages and cleans up resources.
     */
    static void shutdown() {
        spdlog::info("Shutting down logger");
        spdlog::shutdown();
    }
};

} // namespace Core
} // namespace Esther

// Convenience macros for logging
#define LOG_TRACE(...)    spdlog::trace(__VA_ARGS__)
#define LOG_DEBUG(...)    spdlog::debug(__VA_ARGS__)
#define LOG_INFO(...)     spdlog::info(__VA_ARGS__)
#define LOG_WARN(...)     spdlog::warn(__VA_ARGS__)
#define LOG_ERROR(...)    spdlog::error(__VA_ARGS__)
#define LOG_CRITICAL(...) spdlog::critical(__VA_ARGS__)

#endif // ESTHER_LOGGER_HPP
