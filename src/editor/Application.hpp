#pragma once

#include <memory> // for unique_ptr

class Renderer;
class Window;

class Application final
{
public:
  Application();

private:
  std::unique_ptr<Window> window;
  std::unique_ptr<Renderer> renderer;
};