#include "ShaderProgram.hpp"

#include <glad/glad.h>

#include <stdexcept> // for runtime_error

ShaderProgram::ShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
  const auto vertexShader = glCreateShader(GL_VERTEX_SHADER);
  compileShader(vertexShader, vertexShaderSource.data());

  const auto fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  compileShader(fragmentShader, fragmentShaderSource.data());

  program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

ShaderProgram::~ShaderProgram()
{
  glDeleteProgram(program);
}

unsigned int ShaderProgram::getProgram() const
{
  return program;
}

void ShaderProgram::compileShader(unsigned int shader, const char* data) const
{
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
}