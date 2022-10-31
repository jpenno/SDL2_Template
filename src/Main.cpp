#include "../include/App.h"
#include "../include/Config.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>

int main(int argc, char *args[]) {

  App *app = new App();

  if (app->init()) {
    app->run();
  }

  app->close();

  delete app;

  return 0;
}
