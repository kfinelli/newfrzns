#include <memory>
#include <SDL2/SDL.h>

#include "texture.hpp"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
  //does nothing yet
  std::shared_ptr<SDL_Window> gWindow(SDL_CreateWindow( "newfrzns",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ), SDL_DestroyWindow);

  std::shared_ptr<SDL_Renderer> gRenderer(
      SDL_CreateRenderer( gWindow.get(), -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC ),
      SDL_DestroyRenderer);

  texture texture1();

  return 0;

}
