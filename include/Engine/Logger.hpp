#ifndef LOGGER_H
#define LOGGER_H

#include <Build.hpp>

#include <spdlog/spdlog.h>


// Logger names for engine and game logger macros
#define DEFAULT_LOGGER_ENGINE_NAME "Engine"
#define DEFAULT_LOGGER_GAME_NAME "Game"

// Logger pattern shared across application
#define DEFAULT_LOGGER_PATTERN "[%Y-%m-%d %H:%M:%S.%e%z] [%n] [%^%L%$] - %v"

// Macro definitions for loggers calls
#define ENGINE_DEBUG(...)   if (spdlog::get(DEFAULT_LOGGER_ENGINE_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENGINE_NAME)->debug(__VA_ARGS__); }
#define ENGINE_INFO(...)    if (spdlog::get(DEFAULT_LOGGER_ENGINE_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENGINE_NAME)->info(__VA_ARGS__); }
#define ENGINE_WARN(...)    if (spdlog::get(DEFAULT_LOGGER_ENGINE_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENGINE_NAME)->warn(__VA_ARGS__); }
#define ENGINE_ERROR(...)   if (spdlog::get(DEFAULT_LOGGER_ENGINE_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENGINE_NAME)->error(__VA_ARGS__); }
#define GAME_DEBUG(...)     if (spdlog::get(DEFAULT_LOGGER_GAME_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_GAME_NAME)->debug(__VA_ARGS__); }
#define GAME_INFO(...)      if (spdlog::get(DEFAULT_LOGGER_GAME_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_GAME_NAME)->info(__VA_ARGS__); }
#define GAME_WARN(...)      if (spdlog::get(DEFAULT_LOGGER_GAME_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_GAME_NAME)->warn(__VA_ARGS__); }
#define GAME_ERROR(...)     if (spdlog::get(DEFAULT_LOGGER_GAME_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_GAME_NAME)->error(__VA_ARGS__); }

// Macro definitions for trace logging is conditional on release builds
#ifndef RELEASE_BUILD
#define ENGINE_TRACE(...)   (void)0
#define GAME_TRACE(...)     (void)0
#else
#define ENGINE_TRACE(...)   if (spdlog::get(DEFAULT_LOGGER_ENGINE_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENGINE_NAME)->trace(__VA_ARGS__); }
#define GAME_TRACE(...)     if (spdlog::get(DEFAULT_LOGGER_GAME_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_GAME_NAME)->trace(__VA_ARGS__); }
#endif

#endif
