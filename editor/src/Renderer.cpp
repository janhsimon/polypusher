#include "Renderer.hpp"
#include "Vertex.hpp"

#include <glad/glad.h>

#include <array>

Renderer::Renderer()
{
  glClearColor(1.0f, 0.44f, 0.0f, 1.0f);

  const std::string vertexShaderSource = "#version 150 core\n"
                                         "attribute vec3 aPos;\n"
                                         "void main()\n"
                                         "{\n"
                                         "  gl_Position = vec4(aPos, 1.0);\n"
                                         "}";

  const std::string fragmentShaderSource = "#version 150 core\n"
                                           "void main()\n"
                                           "{\n"
                                           "  gl_FragColor = vec4(1.0, 0.0, 1.0, 1.0);\n"
                                           "}";

  shaderProgram = std::make_unique<ShaderProgram>(vertexShaderSource, fragmentShaderSource);

  const std::array<Vertex, 4> vertices = { Vertex(-0.5f, 0.5f, 0.0f), Vertex(0.5f, 0.5f, 0.0f),
                                           Vertex(-0.5f, -0.5f, 0.0f), Vertex(0.5f, -0.5f, 0.0f) };

  glGenVertexArrays(1, &vertexArray);
  glBindVertexArray(vertexArray);

  glGenBuffers(1, &vertexBuffer);
  glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);

  unsigned int indices[] = { 0, 1, 2, 3 };

  glGenBuffers(1, &indexBuffer);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void Renderer::render() const
{
  glClear(GL_COLOR_BUFFER_BIT);

  glUseProgram(shaderProgram->getProgram());

  glBindVertexArray(vertexArray);
  glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, nullptr);

#ifndef NDEBUG
  checkForErrors();
#endif
}

void Renderer::checkForErrors() const
{
  auto error = glGetError();
  if (error == GL_NO_ERROR)
  {
    return;
  }

  std::string output = "OpenGL errors:";
  do
  {
    output += "\n";

    if (error == GL_INVALID_ENUM)
    {
      output += "INVALID_ENUM";
    }
    else if (error == GL_INVALID_VALUE)
    {
      output += "INVALID_VALUE";
    }
    else if (error == GL_INVALID_OPERATION)
    {
      output += "INVALID_OPERATION";
    }
    else if (error == GL_OUT_OF_MEMORY)
    {
      output += "OUT_OF_MEMORY";
    }
    else if (error == GL_INVALID_FRAMEBUFFER_OPERATION)
    {
      output += "INVALID_FRAMEBUFFER_OPERATION";
    }
    else
    {
      output += "Unknown error";
    }

    error = glGetError();
  } while (error != GL_NO_ERROR);

  throw std::runtime_error(output);
}