#pragma once

#include "ShaderProgram.hpp"
#include "Vertex.hpp"

#include <memory> // for unique_ptr, make_unique
#include <vector>

class Batch;

class Renderer final
{
public:
  Renderer(const Batch& batch);

  void render() const;

private:
  // owned
  std::unique_ptr<ShaderProgram> shaderProgram;

  unsigned int vertexArray, vertexBuffer, indexBuffer;
  unsigned int indexCount;

  void loadVertexBufferFromBatch(const Batch& batch);
  void loadIndexBufferFromBatch(const Batch& batch);
  void checkForErrors() const;
};