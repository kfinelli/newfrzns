#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <memory>

#include "util.hpp"

class texture {
  public:
    texture();
    ~texture();

    statusCode init(std::shared_ptr<SDL_Renderer>);
    statusCode load_from_file(std::string f);
    statusCode render(int x, int y, SDL_Rect *clip);
    statusCode set_color(uint8_t r, uint8_t g, uint8_t b);
    statusCode set_alpha(uint8_t a);
    statusCode set_blend_mode(SDL_BlendMode b);
    statusCode reset();

    int get_width() {return mWidth;};
    int get_height() {return mHeight;};

  private:
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> mTexture;
    std::shared_ptr<SDL_Renderer> mRenderer;
    int mWidth, mHeight;
};
