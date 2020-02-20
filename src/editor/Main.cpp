// glad must be included before glfw
#include <glad/glad.h>

#include <GLFW/glfw3.h>

#include <iostream>

int main()
{
  if (!glfwInit())
  {
    std::cout << "Failed to initialize." << std::endl;
    return -1;
  }

  glfwWindowHint(GLFW_RESIZABLE, true);

  const auto window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
  if (!window)
  {
    std::cout << "Failed to create window." << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGL())
  {
    std::cout << "Failed to initialize OpenGL." << std::endl;
    glfwTerminate();
    return -1;
  }

  glClearColor(1.0f, 0.44f, 0.0f, 1.0f);

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
}