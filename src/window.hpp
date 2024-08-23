#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include "img.hpp"

class Texture;

class Window
{
  std::shared_ptr<SDL> sdl;
  SDL_Window* window;
  SDL_Renderer *renderer;

public:
  Window(std::shared_ptr<SDL> sdl, std::string title);

  ~Window();

  std::shared_ptr<Texture> LoadTexture(std::string file);

  void Draw(std::shared_ptr<Texture> tex);

  void Clear(int r, int g, int b);

  void Flip();
};

typedef std::shared_ptr<Window> WindowPtr;

#endif // __WINDOW_HPP__
