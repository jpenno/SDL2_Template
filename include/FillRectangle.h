#ifndef FILLRECTANGLE_H_
#define FILLRECTANGLE_H_
#include "Shape.h"

class FillRectangle : public Shape {
public:
  FillRectangle();
  FillRectangle(Color c, SDL_Rect r);
  void Draw(SDL_Renderer *r);

private:
};

#endif // FILLRECTANGLE_H_
