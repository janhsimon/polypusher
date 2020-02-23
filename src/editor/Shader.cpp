#include "Shader.hpp"

#include <glad/glad.h>

#include <stdexcept> // for runtime_error

Shader::Shader(const std::string& source, unsigned int program, unsigned int type)
{
  shader = glCreateShader(type);

  const auto data = source.data();
  glShaderSource(shader, 1, &data, nullptr);
  glCompileShader(shader);

  int success;
  char infoLog[infoLogSize];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

  if (!success)
  {
    glGetShaderInfoLog(shader, infoLogSize, nullptr, infoLog);
    throw std::runtime_error(infoLog);
  }

  glAttachShader(program, shader);
}

Shader::~Shader()
{
  glDeleteShader(shader);
}