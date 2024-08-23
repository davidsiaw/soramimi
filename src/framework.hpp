#ifndef __FRAMEWORK_HPP__
#define __FRAMEWORK_HPP__

#include "window.hpp"
#include "music.hpp"
#include "texture.hpp"

class Framework
{
  std::shared_ptr<SDL> sdl;
  std::shared_ptr<MIX> mix;
  std::shared_ptr<IMG> img;
  std::shared_ptr<Audio> audio;

public:
  Framework();

  ~Framework();

  WindowPtr CreateWindow(std::string title);

  MusicPtr LoadMusic(std::string file);

  void Volume(int level);

  void Run();
};

#endif // __FRAMEWORK_HPP__
