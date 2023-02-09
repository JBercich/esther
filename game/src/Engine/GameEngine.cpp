#include <Engine/GameEngine.hpp>

void GameEngine::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    windowManager.init();
    assetManager.init();
}

void GameEngine::quit()
{
    assetManager.quit();
    windowManager.quit();
    SDL_Quit();
}