#pragma once

#include <graphics/Renderer.hpp>
#include <interface/Button.hpp>
#include <interface/MainWindow.hpp>

class Application final
{
public:
  Application();

private:
  // owned
  std::unique_ptr<MainWindow> mainWindow;
  std::unique_ptr<Renderer> renderer;
  std::unique_ptr<Button> button1, button2;

  void load();
  void render();
};