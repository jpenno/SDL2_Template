#ifndef SHAPE_H_
#define SHAPE_H_

#include <SDL2/SDL_rect.h>

struct Color {
  int Red;
  int Green;
  int Blue;
  int alapha;
};

class SDL_Renderer;

class Shape {
public:
  Shape();
  Shape(Color a_color, SDL_Rect a_rect);
  virtual void Draw(SDL_Renderer *m_renderer);

  void SetX(float a_x);
  void SetY(float a_y);
  float GetX() { return m_x; }
  float GetY() { return m_y; }

protected:
  Color m_color;
  SDL_Rect m_rect;
  float m_x;
  float m_y;

private:
};

#endif // SHAPE_H_
