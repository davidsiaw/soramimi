#ifndef __IMG_HPP__
#define __IMG_HPP__

#include <SDL2/SDL_image.h>

#include "sdl.hpp"

class IMG
{
  std::shared_ptr<SDL> sdl;
public:
  IMG(std::shared_ptr<SDL> sdl);

  ~IMG();
};

#endif // __IMG_HPP__
