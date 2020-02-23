#pragma once

#include <glm/vec3.hpp>

struct Vertex final
{
  glm::vec3 position;

  Vertex(float x, float y, float z);
};