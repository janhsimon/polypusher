#pragma once

#include "Renderer.hpp"
#include "Window.hpp"

#include <memory> // for unique_ptr, make_unique

class Application final
{
public:
  Application();

private:
  std::unique_ptr<Window> window;
  std::unique_ptr<Renderer> renderer;

  void load();
  void render();
};