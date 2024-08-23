#ifndef __MUSIC_HPP__
#define __MUSIC_HPP__

#include "audio.hpp"

class Music
{
  std::shared_ptr<MIX> mix;
  Mix_Music* music;
public:

  Music(std::shared_ptr<MIX> mix, Mix_Music* music);

  ~Music();

  void Play();
};

typedef std::shared_ptr<Music> MusicPtr;

#endif // __MUSIC_HPP__
