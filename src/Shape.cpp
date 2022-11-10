#include "../include/Shape.h"

Shape::Shape() {}
Shape::Shape(Color a_color, SDL_Rect a_rect) {
  m_color = a_color;
  m_rect = a_rect;
  m_x = m_rect.x;
  m_y = m_rect.y;
}

void Shape::SetX(float a_x) {
  m_x = a_x;
  m_rect.x = (int)m_x;
}

void Shape::SetY(float a_y) {
  m_y = a_y;
  m_rect.y = (int)m_y;
}
