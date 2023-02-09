#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <Engine/AssetManager.hpp>
#include <Engine/WindowManager.hpp>

class GameEngine
{
public:
    AssetManager assetManager;
    WindowManager windowManager;
    void init();
    void quit();
};

#endif