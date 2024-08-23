#include "mix.hpp"

MIX::MIX(std::shared_ptr<SDL> sdl) : sdl(sdl)
{
  // Initialize SDL_mixer
  if (!(Mix_Init(MIX_INIT_OGG)))
  {
    printf("Mix_Init Error: %s\n", Mix_GetError());
    exit(1);
  }
}

MIX::~MIX()
{
  Mix_Quit();
}
