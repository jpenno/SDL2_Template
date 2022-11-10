#ifndef LINE_H_
#define LINE_H_
#include "../include/Shape.h"

class Line : public Shape {
public:
  Line();
  Line(Color a_color, SDL_Rect a_rect);
  void Draw(SDL_Renderer *a_renderer);
  int GetX1() { return m_rect.x; }
  int GetX2() { return m_rect.w; }
  int GetY1() { return m_rect.y; }
  int GetY2() { return m_rect.h; }
  void SetX1(int a_x) { m_rect.x = a_x; }
  void SetX2(int a_x) { m_rect.w = a_x; }
  void SetY1(int a_y) { m_rect.y = a_y; }
  void SetY2(int a_y) { m_rect.h = a_y; }

private:
};

#endif // LINE_H_
