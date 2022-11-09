#ifndef SHAPE_H_
#define SHAPE_H_

struct Color {
  int Red;
  int Green;
  int Blue;
  int alapha;
};

class SDL_Renderer;
class Shape {
public:
  virtual void Draw(SDL_Renderer *m_renderer) = 0;

protected:
  Color m_color;

private:
};

#endif // SHAPE_H_
