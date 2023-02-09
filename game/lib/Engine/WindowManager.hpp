#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

#define WINDOW_TITLE "Game Title"
#define WINDOW_WIDTH 1440
#define WINDOW_HEIGHT 900
#define WINDOW_RES_WIDTH 1440
#define WINDOW_RES_HEIGHT 900
#define WINDOW_BACKGROUND_R 0x00
#define WINDOW_BACKGROUND_G 0x00
#define WINDOW_BACKGROUND_B 0x00

class WindowManager
{
private:
    string windowTitle = WINDOW_TITLE;
    int windowWidth = WINDOW_WIDTH;
    int windowHeight = WINDOW_HEIGHT;
    int resolutionWidth = WINDOW_RES_WIDTH;
    int resolutionHeight = WINDOW_RES_HEIGHT;

public:
    SDL_Window *window;
    SDL_Renderer *renderer;
    void init();
    void quit();
};

// class Resolution
// {
// public:
//     constexpr Resolution(int const &w, int const &h);
//     constexpr int const &getWidth() const {};
//     constexpr int const &getHeight() const {};

// private:
//     int width;
//     int height;
// };

#endif
