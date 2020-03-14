#include "Batch.hpp"
#include "Renderer.hpp"

void Batch::addQuad(float x1, float y1, float x2, float y2)
{
  const auto firstVertex = static_cast<unsigned int>(vertices.size());

  vertices.emplace_back(Vertex(x1, y2, 0.0f));
  vertices.emplace_back(Vertex(x2, y2, 0.0f));
  vertices.emplace_back(Vertex(x1, y1, 0.0f));
  vertices.emplace_back(Vertex(x2, y1, 0.0f));

  indices.emplace_back(firstVertex + 0u);
  indices.emplace_back(firstVertex + 1u);
  indices.emplace_back(firstVertex + 2u);

  indices.emplace_back(firstVertex + 1u);
  indices.emplace_back(firstVertex + 2u);
  indices.emplace_back(firstVertex + 3u);
}

const std::vector<Vertex>& Batch::getVertices() const
{
  return vertices;
}

const std::vector<unsigned int>& Batch::getIndices() const
{
  return indices;
}