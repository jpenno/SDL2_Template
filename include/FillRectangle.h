#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "Shape.h"
#include <SDL2/SDL.h>

class FillRectangle : public Shape {
public:
  FillRectangle();
  FillRectangle(Color c, SDL_Rect r);
  void Draw(SDL_Renderer *r);

private:
  SDL_Rect m_rect;
};

#endif // RECTANBLE_H_
