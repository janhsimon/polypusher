#pragma once

#include "Application.hpp"
#include "Batch.hpp"

#include <iostream>  // for cout, endl
#include <stdexcept> // for runtime_error

Application::Application()
{
  load();

  while (!window->shouldClose())
  {
    window->waitForEvents();
    render();
    window->swapBuffers();
  }
}

void Application::load()
{
  window = std::make_unique<Window>();

  Batch batch;
  batch.addQuad(-0.9f, -0.9f, -0.75f, -0.75f);
  batch.addQuad(0.5f, 0.5f, 0.9f, 0.9f);

  renderer = std::make_unique<Renderer>(batch);
}

void Application::render()
{
  renderer->render();
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