#ifndef RECTANGLE_H_
#define RECTANGLE_H_
#include "../include/Shape.h"

class SDL_Rect;

class Rectangle : public Shape {
public:
  Rectangle();
  Rectangle(Color c, SDL_Rect r);
  void Draw(SDL_Renderer *r);

private:
};
#endif // RECTANGLE_H_
