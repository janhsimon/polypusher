#pragma once

#include <vector>

class Button;

struct GLFWwindow;

class MainWindow final
{
public:
  MainWindow();
  ~MainWindow();

  GLFWwindow* getGLFWWindow() const;
  bool shouldClose() const;
  void waitForEvents() const;
  void swapBuffers() const;

  void registerButton(Button* button);

private:
  static inline constexpr auto glVersionMajor = 3;
  static inline constexpr auto glVersionMinor = 2;

  // owned
  GLFWwindow* window = nullptr;

  static void onMouseMove(GLFWwindow* window, double x, double y);

  static std::vector<Button*> buttons;
};