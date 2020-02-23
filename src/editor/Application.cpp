#pragma once

#include "Application.hpp"
#include "Renderer.hpp"
#include "Window.hpp"

#include <iostream>  // for cout, endl
#include <stdexcept> // for runtime_error

Application::Application()
{
  window = std::make_unique<Window>();
  renderer = std::make_unique<Renderer>();

  while (!window->shouldClose())
  {
    window->waitForEvents();
    renderer->render();
    window->swapBuffers();
  }
}

int main()
{
  try
  {
    Application app;
  }
  catch (const std::runtime_error& error)
  {
    std::cout << error.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}