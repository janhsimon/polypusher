#pragma once

#include "Vertex.hpp"

#include <vector>

class Batch final
{
public:
  void addQuad(float x1, float y1, float x2, float y2);
  const std::vector<Vertex>& getVertices() const;
  const std::vector<unsigned int>& getIndices() const;

private:
  std::vector<Vertex> vertices;
  std::vector<unsigned int> indices;
};