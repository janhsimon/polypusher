#include "Window.hpp"

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

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
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);
  glfwWindowHint(GLFW_RESIZABLE, true);

  window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
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

void Window::swapBuffers() const
{
  glClearColor(1.0f, 0.44f, 0.0f, 1.0f); // TODO: do not call repeatedly
  glClear(GL_COLOR_BUFFER_BIT);          // TODO: move into future renderer class
  glfwSwapBuffers(window);
  glfwWaitEvents(); // TODO: move into future event queue class
}