#include "texture.hpp"

Texture::Texture(std::shared_ptr<SDL> sdl, SDL_Texture* texture) : sdl(sdl), texture(texture)
{ }

Texture::~Texture()
{
  SDL_DestroyTexture(texture);
}

SDL_Texture* Texture::get_texture()
{
  return texture;
}
