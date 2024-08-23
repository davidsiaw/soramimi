#include "audio.hpp"

Audio::Audio(std::shared_ptr<MIX> mix) : mix(mix)
{
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024) < 0)
  {
    printf("SDL_mixer could not initialize! %s\n", Mix_GetError());
    exit(1);
  }
}

Audio::~Audio()
{
  Mix_CloseAudio();
}
