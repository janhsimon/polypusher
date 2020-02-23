#include "Window.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h> // for gladLoadGLLoader, GLADloadproc

#include <stdexcept> // for runtime_error

Window::Window()
{
  if (!glfwInit())
  {
    throw std::runtime_error("Failed to initialize.");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, glVersionMajor);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, glVersionMinor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, true);

  window = glfwCreateWindow(640, 480, "Polypusher", nullptr, nullptr);
  if (!window)
  {
    throw std::runtime_error("Failed to create window.");
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
  {
    throw std::runtime_error("Failed to initialize OpenGL.");
  }
}

Window::~Window()
{
  if (window)
  {
    glfwDestroyWindow(window);
  }

  glfwTerminate();
}

bool Window::shouldClose() const
{
  return glfwWindowShouldClose(window);
}

void Window::waitForEvents() const
{
  glfwWaitEvents();
}

void Window::swapBuffers() const
{
  glfwSwapBuffers(window);
}