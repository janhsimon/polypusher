#pragma once

class Batch;

class Button final
{
public:
  Button(Batch& batch, int x, int y, int w, int h);

  bool onMouseMove(int x, int y);

private:
  int x, y, w, h;
};