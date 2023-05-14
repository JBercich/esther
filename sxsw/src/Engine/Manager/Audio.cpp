#include <Engine/Manager/Audio.hpp>

#include <SDL2_Mixer/SDL_Mixer.h>
#include <spdlog/spdlog.h>

#define AUDIO_MIXER_FREQUENCY 48000
#define AUDIO_MIXER_CHANNELS 2
#define AUDIO_MIXER_CHUNKSIZE 1024

// Initialise an AudioManager instance
void AudioManager::init() {
  // Load in the needed mixer codecs
  int initResult = Mix_Init(MIX_INIT_MP3 | MIX_INIT_FLAC);
  if (initResult == 0) {
    SPDLOG_ERROR(Mix_GetError());
  }

  // Init the mixer audio manager
  initResult = Mix_OpenAudio(AUDIO_MIXER_FREQUENCY, MIX_DEFAULT_FORMAT,
                             AUDIO_MIXER_CHANNELS, AUDIO_MIXER_CHUNKSIZE);
  if (initResult == -1) {
    SPDLOG_ERROR(Mix_GetError());
  }
}

// Quit an AudioManager instance
void AudioManager::quit() { Mix_Quit(); }