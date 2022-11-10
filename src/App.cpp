#include "../include/App.h"
#include "../include/Config.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

App::App() {}

void App::Run() {
  // Load media
  if (!loadMedia()) {
    printf("Failed to load media!\n");
  } else {
    // Main loop flag
    bool quit = false;

    // Event handler
    SDL_Event e;

    // While application is Running
    while (!quit) {
      // Handle events on queue
      while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT) {
          quit = true;
        }
      }
      Draw();
    }
  }
}

bool App::Init() {
  // Initialization flag
  bool success = true;

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
    success = false;
  } else {
    // Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
      printf("Warning: Linear texture filtering not enabled!");
    }

    // Create window
    m_window = SDL_CreateWindow("SDL Template", SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (m_window == NULL) {
      printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
      success = false;
    } else {
      // Create renderer for window
      m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
      if (m_renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n",
               SDL_GetError());
        success = false;
      } else {
        // Initialize renderer color
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        // Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
          printf("SDL_image could not initialize! SDL_image Error: %s\n",
                 IMG_GetError());
          success = false;
        }
      }
    }
  }

  SDL_Rect fillRect2 = {100, 100, 100, 100};
  Color color = Color{
      0xFF,
      0x00,
      0x00,
      0xFF,
  };
  r = FillRectangle(color, fillRect2);
  fillRect2.x += 100;
  fillRect2.y += 100;
  color.Red = 0x00;
  color.Blue = 0xFF;
  test_r = Rectangle(color, fillRect2);
  return success;
}

bool App::loadMedia() {
  // Loading success flag
  bool success = true;

  // Load PNG texture
  m_texture = loadTexture("../Res/texture.png");
  if (m_texture == NULL) {
    printf("Failed to load texture image!\n");
    success = false;
  }

  return success;
}

void App::Draw() {

  // Clear screen
  SDL_RenderClear(m_renderer);

  // Render texture to screen
  SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);

  // Render filled quad
  r.Draw(m_renderer);
  r.SetX((float)(r.GetX() + 0.001f));

  // Render green outlined quad
  test_r.Draw(m_renderer);
  test_r.SetX((float)(test_r.GetX() + 0.001f));

  // Draw blue horizontal line
  SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0xFF, 0xFF);
  SDL_RenderDrawLine(m_renderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH,
                     SCREEN_HEIGHT / 2);

  // Draw vertical line of yellow dots
  SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0x00, 0xFF);
  for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
    SDL_RenderDrawPoint(m_renderer, SCREEN_WIDTH / 2, i);
  }

  // Update screen
  SDL_RenderPresent(m_renderer);
}

void App::Close() {
  // Free loaded image
  SDL_DestroyTexture(m_texture);
  m_texture = NULL;

  // Destroy window
  SDL_DestroyRenderer(m_renderer);
  SDL_DestroyWindow(m_window);
  m_window = NULL;
  m_renderer = NULL;

  // Quit SDL subsystems
  IMG_Quit();
  SDL_Quit();
  // delete r;
}

SDL_Texture *App::loadTexture(std::string a_path) {
  // The final texture
  SDL_Texture *newTexture = NULL;

  // Load image at specified path
  SDL_Surface *loadedSurface = IMG_Load(a_path.c_str());
  if (loadedSurface == NULL) {
    printf("Unable to load image %s! SDL_image Error: %s\n", a_path.c_str(),
           IMG_GetError());
  } else {
    // Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
    if (newTexture == NULL) {
      printf("Unable to create texture from %s! SDL Error: %s\n",
             a_path.c_str(), SDL_GetError());
    }

    // Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
  }

  return newTexture;
}
