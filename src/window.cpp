#include "window.hpp"
#include "texture.hpp"

// Screen dimensions
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024

Window::Window(std::shared_ptr<SDL> sdl, std::string title) : sdl(sdl)
{
  window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window)
  {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    exit(1);
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    exit(1);
  }
}

Window::~Window()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

void Window::Draw(std::shared_ptr<Texture> tex)
{
  SDL_RenderCopy(renderer, tex->get_texture(), NULL, NULL);
}

std::shared_ptr<Texture> Window::LoadTexture(std::string file)
{
  SDL_Surface* surface = IMG_Load(file.c_str());
  if (!surface)
  {
    printf("IMG_Load Error: %s\n", IMG_GetError());
    exit(1);
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  if (!texture)
  {
    printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    exit(1);
  }

  return std::make_shared<Texture>(sdl, texture);
}

void Window::Clear(int r, int g, int b)
{
  SDL_SetRenderDrawColor(renderer, r, g, b, 255);
  SDL_RenderClear(renderer);
}

void Window::Flip()
{
  SDL_RenderPresent(renderer);
}
