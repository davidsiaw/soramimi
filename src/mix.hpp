#ifndef __MIX_HPP__
#define __MIX_HPP__

#include <SDL2/SDL_mixer.h>

#include "sdl.hpp"

class MIX
{
  std::shared_ptr<SDL> sdl;
public:
  MIX(std::shared_ptr<SDL> sdl);

  ~MIX();
};


#endif // __MIX_HPP__
