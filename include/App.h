#ifndef APP_H_
#define APP_H_

#include "../include/FillRectangle.h"
#include <string>

class SDL_Texture;
class SDL_Window;
class SDL_Renderer;
// class Rectangle;

class App {
public:
  App();

  void Run();
  bool Init();
  void Close();

  SDL_Texture *loadTexture(std::string path);
  SDL_Window *getWindow() { return m_window; } // The window renderer
  SDL_Renderer *getRenderer() { return m_renderer; }

private:
  bool loadMedia();
  void Draw();
  // The window we'll be rendering to
  SDL_Window *m_window = nullptr;

  // The window renderer
  SDL_Renderer *m_renderer = nullptr;

  // Current displayed texture
  SDL_Texture *m_texture = nullptr;

  FillRectangle r;
};
#endif // APP_H_
