#include <SDL2_Mixer/SDL_Mixer.h>
#include <spdlog/spdlog.h>

#include <Engine/AudioManager.hpp>
#include <stdexcept>

#define AUDIO_MIXER_FREQUENCY 48000
#define AUDIO_MIXER_CHANNELS 2
#define AUDIO_MIXER_CHUNKSIZE 1024

/**
 * Initialise an AssetManager instance.
 */
void AudioManager::init() {
  int initResult = Mix_Init(MIX_INIT_MP3 | MIX_INIT_WAVPACK);
  if (initResult == 0) {
    spdlog::error("Failed to start AudioManager: {}", Mix_GetError());
    throw runtime_error();
  }

  int initResult = Mix_OpenAudio(AUDIO_MIXER_FREQUENCY, MIX_DEFAULT_FORMAT,
                                 AUDIO_MIXER_CHANNELS, AUDIO_MIXER_CHUNKSIZE);
  if (initResult == -1) {
    spdlog::error("Failed to start AudioManager: {}", Mix_GetError());
    throw runtime_error();
  }
}

/**
 * Quit an AssetManager instance.
 */
void AudioManager::quit() { Mix_Quit(); }