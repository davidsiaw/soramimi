#include "music.hpp"

Music::Music(std::shared_ptr<MIX> mix, Mix_Music* music) : mix(mix), music(music)
{

}

Music::~Music()
{
  Mix_FreeMusic(music);
}

void Music::Play()
{
  Mix_PlayMusic(music, 0);
}
