/**
 * @file main.cpp
 * @brief Entry point for the Esther game engine
 * 
 * This file demonstrates basic logging setup for the engine.
 * As development progresses, this will initialize SDL3, OpenGL,
 * and the main game loop.
 */

#include <iostream>

// TODO: Uncomment after spdlog is integrated in CMake (Issue #3)
// #include "Engine/Core/Utils/Logger.hpp"

int main()
{
    // Initialize logging (uncomment after Issue #3 is complete)
    // Esther::Core::Logger::init("esther.log");
    // LOG_INFO("Esther Game Engine starting...");
    
    std::cout << "Esther Game Engine - Development Build" << std::endl;
    std::cout << "TODO: Initialize SDL3 (Issue #1)" << std::endl;
    std::cout << "TODO: Initialize OpenGL Context (Issue #2)" << std::endl;
    std::cout << "TODO: Start Game Loop (Issue #4)" << std::endl;
    
    // LOG_INFO("Engine initialization complete");
    // LOG_INFO("Shutting down...");
    // Esther::Core::Logger::shutdown();
    
    return 0;
}
