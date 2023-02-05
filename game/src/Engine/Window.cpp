
#include <SDL2/SDL.h>

#include <Engine/Window.h>

class Resolution
{
public:
    constexpr Resolution(int const &w, int const &h) : width(w), height(h){};
    constexpr int const &getWidth() const { return width; };
    constexpr int const &getHeight() const { return height; };

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
    int updateWindowResolution(Resolution *resolution);
};