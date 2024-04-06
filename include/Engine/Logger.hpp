#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <BuildConfig.hpp>

#include <spdlog/spdlog.h>


// Logger names for engine and game logger macros
#define DEFAULT_LOGGER_ENG_NAME "ENG"
#define DEFAULT_LOGGER_RUN_NAME "RUN"

// Logger pattern shared across application
#define DEFAULT_LOGGER_PATTERN "[%Y-%m-%d %H:%M:%S.%e%z] [%n] [%^%L%$] - %v"

// Macro definitions for loggers calls
#define ENG_DEBUG(...)  if (spdlog::get(DEFAULT_LOGGER_ENG_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENG_NAME)->debug(__VA_ARGS__); }
#define RUN_DEBUG(...)  if (spdlog::get(DEFAULT_LOGGER_RUN_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_RUN_NAME)->debug(__VA_ARGS__); }
#define ENG_INFO(...)   if (spdlog::get(DEFAULT_LOGGER_ENG_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENG_NAME)->info(__VA_ARGS__); }
#define RUN_INFO(...)   if (spdlog::get(DEFAULT_LOGGER_RUN_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_RUN_NAME)->info(__VA_ARGS__); }
#define ENG_WARN(...)   if (spdlog::get(DEFAULT_LOGGER_ENG_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENG_NAME)->warn(__VA_ARGS__); }
#define RUN_WARN(...)   if (spdlog::get(DEFAULT_LOGGER_RUN_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_RUN_NAME)->warn(__VA_ARGS__); }
#define ENG_ERROR(...)  if (spdlog::get(DEFAULT_LOGGER_ENG_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENG_NAME)->error(__VA_ARGS__); }
#define RUN_ERROR(...)  if (spdlog::get(DEFAULT_LOGGER_RUN_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_RUN_NAME)->error(__VA_ARGS__); }

// Macro definitions for trace logging is conditional on release builds
#ifndef RELEASE_BUILD
#define ENG_TRACE(...)  (void)0
#define RUN_TRACE(...)  (void)0
#else
#define ENG_TRACE(...)  if (spdlog::get(DEFAULT_LOGGER_ENG_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_ENG_NAME)->trace(__VA_ARGS__); }
#define RUN_TRACE(...)  if (spdlog::get(DEFAULT_LOGGER_RUN_NAME) != nullptr) { spdlog::get(DEFAULT_LOGGER_RUN_NAME)->trace(__VA_ARGS__); }
#endif

#endif
