#pragma once

#include "Application.hpp"

#include <graphics/Batch.hpp>

#include <iostream>  // for cout, endl
#include <stdexcept> // for runtime_error

Application::Application()
{
  load();

  while (!mainWindow->shouldClose())
  {
    mainWindow->waitForEvents();
    render();
    mainWindow->swapBuffers();
  }
}

void Application::load()
{
  mainWindow = std::make_unique<MainWindow>();

  Batch batch;

  button1 = std::make_unique<Button>(batch, 10, 10, 100, 100);
  button2 = std::make_unique<Button>(batch, 30, 30, 100, 30);
  mainWindow->registerButton(button1.get());
  mainWindow->registerButton(button2.get());

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