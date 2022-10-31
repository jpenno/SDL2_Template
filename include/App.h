#ifndef APP_H_
#define APP_H_

#include <string>

class SDL_Texture;
class SDL_Window;
class SDL_Renderer;

class App {
public:
  App();

  void run();
  bool init();
  void close();
  SDL_Texture *loadTexture(std::string path);

  SDL_Window *getWindow() { return m_window; } // The window renderer
  SDL_Renderer *getRenderer() { return m_renderer; }

private:
  bool loadMedia();
  // The window we'll be rendering to
  SDL_Window *m_window = NULL;

  // The window renderer
  SDL_Renderer *m_renderer = NULL;

  // Current displayed texture
  SDL_Texture *m_texture = NULL;
};
#endif // APP_H_
