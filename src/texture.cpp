texture::texture() :
  mTexture(nullptr, SDL_DestroyTexture), mWidth(0), mHeight(0) {
  }

texture::~texture() {};

statusCode texture::reset() {
  mWidth = mHeight = 0;
  return statusCode::kSuccess;
}


statusCode texture::load_from_file(std::string f) {
  reset();

  //Load image at specified path
  std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>
    loadedSurface(IMG_Load( path.c_str() ), SDL_FreeSurface);

  if (CHECK(loadedSurface != nullptr, "Unable to load image %s, SDL_image Error: %s\n", path.c_str(), IMG_GetError()) == statusCode::kFail) { return statusCode::kFail; }

  //Color key image
  SDL_SetColorKey( loadedSurface.get(), SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

  //Create texture from surface pixels
  mTexture.reset(SDL_CreateTextureFromSurface( gRenderer.get(), loadedSurface.get() ));

  if(CHECK(mTexture != nullptr, "Unable to create texture from %s, SDL Error: %s\n", path.c_str(), SDL_GetError() ) == statusCode::kFail) {return statusCode::kFail;}

  //Get image dimensions
  mWidth = loadedSurface->w;
  mHeight = loadedSurface->h;

  //Return success
  return statusCode::kSuccess;

}

statusCode texture::render() {

}
