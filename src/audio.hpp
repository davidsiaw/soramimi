#ifndef __AUDIO_HPP__
#define __AUDIO_HPP__

#include "mix.hpp"

class Audio
{
  std::shared_ptr<MIX> mix;
public:
  Audio(std::shared_ptr<MIX> mix);

  ~Audio();
};

#endif // __AUDIO_HPP__
