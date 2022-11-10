#include "../include/Rectangle.h"
#include <SDL2/SDL.h>

Rectangle::Rectangle() {}

Rectangle::Rectangle(Color a_color, SDL_Rect a_rect) : Shape(a_color, a_rect) {}

void Rectangle::Draw(SDL_Renderer *a_renderer) {
  SDL_SetRenderDrawColor(a_renderer, m_color.Red, m_color.Green, m_color.Blue,
                         m_color.alapha);
  SDL_RenderDrawRect(a_renderer, &m_rect);
}
