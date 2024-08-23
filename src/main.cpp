#include "framework.hpp"
#include <stdio.h>

int main(int argc, char *argv[])
{
  auto fw = std::make_shared<Framework>();

  auto window = fw->CreateWindow("SDL Image Test");

  SDL_ShowCursor(SDL_DISABLE);

  auto tex = window->LoadTexture("wp.jpg");

  auto mus = fw->LoadMusic("t1.ogg");

  fw->Volume(20);
  mus->Play();

  // Clear the screen with a solid color
  window->Clear(0,0,0);

  // Render the image
  window->Draw(tex);
  window->Flip();

  fw->Run();

  return 0;
}
