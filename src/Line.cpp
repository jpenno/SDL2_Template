#include "../include/Line.h"
#include <SDL2/SDL.h>

Line::Line() {}

Line::Line(Color a_color, SDL_Rect a_rect) : Shape(a_color, a_rect) {}

void Line::Draw(SDL_Renderer *a_renderer) {
  Shape::Draw(a_renderer);
  SDL_RenderDrawLine(a_renderer, m_rect.x, m_rect.y, m_rect.w, m_rect.h);
}
