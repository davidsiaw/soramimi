#include "sdl.hpp"

SDL::SDL()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
  {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    exit(1);
  }
}

SDL::~SDL()
{
  SDL_Quit();
}
