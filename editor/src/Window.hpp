#pragma once

struct GLFWwindow;

class Window final
{
public:
  Window();
  ~Window();

  bool shouldClose() const;
  void waitForEvents() const;
  void swapBuffers() const;

private:
  static inline constexpr auto glVersionMajor = 3;
  static inline constexpr auto glVersionMinor = 2;

  // not owned
  GLFWwindow* window = nullptr;
};