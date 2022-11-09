#include "../include/FillRectangle.h"

FillRectangle::FillRectangle() {}

FillRectangle::FillRectangle(Color a_color, SDL_Rect a_rect) {
  m_rect = a_rect;
  m_color = a_color;
}

void FillRectangle::Draw(SDL_Renderer *a_renderer) {
  // Render filled quad
  SDL_SetRenderDrawColor(a_renderer, m_color.Red, m_color.Green, m_color.Blue,
                         m_color.alapha);
  SDL_RenderFillRect(a_renderer, &m_rect);
}
