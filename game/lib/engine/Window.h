/**
 * @file Window.h
 * @author Josh Bercich (joshbercich@gmail.com)
 * @brief Set default runtime window settings.
 * @date 2023-02-05
 *
 * Copyright (c) 2023 Josh Bercich (joshbercich@gmail.com)
 *
 */
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

// Default window resolution
#define WINDOW_DEFAULT_RESOLUTION_WIDTH 1440
#define WINDOW_DEFAULT_RESOLUTION_HEIGHT 900

// Default fullscreen flag
#define WINDOW_DEFAULT_FULLSCREEN true

// Default window background
#define WINDOW_DEFAULT_BACKGROUND_R 0x00
#define WINDOW_DEFAULT_BACKGROUND_G 0x00
#define WINDOW_DEFAULT_BACKGROUND_B 0x00

// Define a resolution object for some object dimensions
class Resolution
{
public:
    constexpr Resolution(int const &w, int const &h);
    constexpr int const &getWidth() const {};
    constexpr int const &getHeight() const {};

private:
    int width;
    int height;
};

// Runtime window instantiation
class Window
{
public:
    SDL_Window *window;
    Resolution resolution;
    int init();
    int close();
    int updateWindowResolution(WindowResolution *resolution);
};

#endif