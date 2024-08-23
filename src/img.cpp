#include "img.hpp"

IMG::IMG(std::shared_ptr<SDL> sdl) : sdl(sdl)
{
  // Initialize SDL_image
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
  {
    printf("IMG_Init Error: %s\n", IMG_GetError());
    exit(1);
  }
}

IMG::~IMG()
{
  IMG_Quit();
}
