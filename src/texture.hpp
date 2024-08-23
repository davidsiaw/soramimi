#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "window.hpp"

class Texture
{
  std::shared_ptr<SDL> sdl;
  SDL_Texture* texture;

public:
  Texture(std::shared_ptr<SDL> sdl, SDL_Texture* texture);

  ~Texture();

  SDL_Texture* get_texture();
};

typedef std::shared_ptr<Texture> TexturePtr;

#endif // __TEXTURE_HPP__
