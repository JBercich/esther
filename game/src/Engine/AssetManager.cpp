#include <Engine/AssetManager.hpp>

#include <stdexcept>
#include <SDL2_Image/SDL_Image.h>

void AssetManager::init()
{
    IMG_SetError(NULL);
    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
    {
        string errorMessage = "IMG_Init: ";
        errorMessage += IMG_GetError();
        throw runtime_error(errorMessage);
    }
}

void AssetManager::quit()
{
    IMG_Quit();
}