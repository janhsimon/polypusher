#pragma once

class Renderer final
{
public:
  Renderer();
  ~Renderer();

  void render() const;

private:
  unsigned int vertexArray, vertexBuffer, indexBuffer;
  unsigned int shaderProgram;

  void checkForErrors() const;
};