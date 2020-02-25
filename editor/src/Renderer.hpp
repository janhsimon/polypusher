#pragma once

#include "ShaderProgram.hpp"

#include <memory> // for unique_ptr, make_unique

class Renderer final
{
public:
  Renderer();

  void render() const;

private:
  // owned
  std::unique_ptr<ShaderProgram> shaderProgram;

  unsigned int vertexArray, vertexBuffer, indexBuffer;

  void checkForErrors() const;
};