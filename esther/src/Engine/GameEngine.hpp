#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include <Engine/Manager/Asset.hpp>
#include <Engine/Manager/Audio.hpp>
#include <Engine/Manager/Font.hpp>
#include <Engine/Manager/Renderer.hpp>

class GameEngine {
public:
AssetManager assetManager;
WindowManager windowManager;
AudioManager audioManager;
FontManager fontManager;
void init();
void quit();
};

#endif