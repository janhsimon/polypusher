#include "MainWindow.hpp"
#include "Button.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h> // for gladLoadGLLoader, GLADloadproc

#include <stdexcept> // for runtime_error

std::vector<Button*> MainWindow::buttons;

MainWindow::MainWindow()
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

  glfwSetCursorPosCallback(window, MainWindow::onMouseMove);
}

MainWindow::~MainWindow()
{
  if (window)
  {
    glfwDestroyWindow(window);
  }

  glfwTerminate();
}

GLFWwindow* MainWindow::getGLFWWindow() const
{
  return window;
}

bool MainWindow::shouldClose() const
{
  return glfwWindowShouldClose(window);
}

void MainWindow::waitForEvents() const
{
  glfwWaitEvents();
}

void MainWindow::swapBuffers() const
{
  glfwSwapBuffers(window);
}

void MainWindow::registerButton(Button* button)
{
  buttons.emplace_back(button);
}

void MainWindow::onMouseMove(GLFWwindow* window, double x, double y)
{
  const auto x_ = static_cast<int>(x);
  const auto y_ = static_cast<int>(y);
  for (const auto& button : buttons)
  {
    if (button->onMouseMove(x_, y_))
    {
      // stop processing if the button consumed the event
      return;
    }
  }
}