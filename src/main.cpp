#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>

// Screen dimensions
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 1024

int main(int argc, char *argv[]) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }

  // Initialize SDL_image
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    printf("IMG_Init Error: %s\n", IMG_GetError());
    SDL_Quit();
    return 1;
  }

  // Initialize SDL_mixer
  if (!(Mix_Init(MIX_INIT_OGG))) {
    printf("Mix_Init Error: %s\n", Mix_GetError());
    SDL_Quit();
    return 1;
  }

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 1, 1024) < 0) {
      printf("SDL_mixer could not initialize! %s\n", Mix_GetError());
    SDL_Quit();
    return 1;
  }


  SDL_Window *window = SDL_CreateWindow("SDL Image Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
  if (!window) {
    printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer) {
    printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  SDL_ShowCursor(SDL_DISABLE);

  // Load image
  SDL_Surface *imageSurface = IMG_Load("wp.jpg");
  if (!imageSurface) {
    printf("IMG_Load Error: %s\n", IMG_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  // Mix
  Mix_Music *music = Mix_LoadMUS("t1.ogg");
  if (!music) {
    printf("Mix_LoadMUS Error: %s\n", Mix_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  Mix_VolumeMusic(20);

  Mix_PlayMusic(music, 0);

  SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
  SDL_FreeSurface(imageSurface);
  if (!imageTexture) {
    printf("SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
    return 1;
  }

  // Clear the screen with a solid color
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
  SDL_RenderClear(renderer);

  // Render the image
  SDL_RenderCopy(renderer, imageTexture, NULL, NULL);
  SDL_RenderPresent(renderer);

  SDL_Event event;
  bool running = true;

  while(running) {
    if(SDL_WaitEvent(&event)) {
      switch(event.type) {
        case SDL_QUIT:
          running = false;
      }
    }
  }

  // Clean up
  SDL_DestroyTexture(imageTexture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  Mix_FreeMusic(music);
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();

  return 0;
}
