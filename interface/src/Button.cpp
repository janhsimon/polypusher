#include "Button.hpp"

#include <graphics/Batch.hpp>

#include <iostream> // for cout, endl

Button::Button(Batch& batch, int x, int y, int w, int h) : x(x), y(y), w(w), h(h)
{
  const auto x1 = static_cast<float>(x);
  const auto y1 = static_cast<float>(y);
  const auto x2 = static_cast<float>(x + w);
  const auto y2 = static_cast<float>(y + h);
  batch.addQuad(x1, y1, x2, y2);
}

bool Button::onMouseMove(int x, int y)
{
  if (x >= this->x && x < this->x + w)
  {
    if (y >= this->y && y < this->y + h)
    {
      std::cout << "Button consumed mouse move event." << std::endl;

      // we consumed the event
      return true;
    }
  }

  // we did not consume the event
  return false;
}