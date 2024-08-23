#include "framework.hpp"

Framework::Framework() :
  sdl(std::make_shared<SDL>()),
  mix(std::make_shared<MIX>(sdl)),
  img(std::make_shared<IMG>(sdl)),
  audio(std::make_shared<Audio>(mix))
{ }

Framework::~Framework()
{ }

WindowPtr Framework::CreateWindow(std::string title)
{
  return std::make_shared<Window>(sdl, title);
}

MusicPtr Framework::LoadMusic(std::string file)
{
  // Mix
  Mix_Music *music = Mix_LoadMUS(file.c_str());
  if (!music) {
    printf("Mix_LoadMUS Error: %s\n", Mix_GetError());
    exit(1);
  }
  return std::make_shared<Music>(mix, music);
}

void Framework::Volume(int level)
{
  Mix_VolumeMusic(20);
}

void Framework::Run()
{
  SDL_Event event;
  bool running = true;

  while(running)
  {
    if(SDL_WaitEvent(&event))
    {
      switch(event.type)
      {
        case SDL_QUIT:
          running = false;
      }
    }
  }
}
