#include "Window.hpp"

#include <iostream>  // for cout, endl
#include <stdexcept> // for runtime_error

int main()
{
  try
  {
    Window window;

    while (!window.shouldClose())
    {
      window.swapBuffers();
    }
  }
  catch (const std::runtime_error& error)
  {
    std::cout << error.what() << std::endl;
    return EXIT_FAILURE;
  }
}