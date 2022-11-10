#include "../include/FillRectangle.h"
#include <SDL2/SDL.h>

FillRectangle::FillRectangle() {}

FillRectangle::FillRectangle(Color a_color, SDL_Rect a_rect)
    : Shape(a_color, a_rect) {}

void FillRectangle::Draw(SDL_Renderer *a_renderer) {
  // Render filled quad
  Shape::Draw(a_renderer);
  // SDL_SetRenderDrawColor(a_renderer, m_color.Red, m_color.Green,
  // m_color.Blue,
  //                        m_color.alapha);
  SDL_RenderFillRect(a_renderer, &m_rect);
}
