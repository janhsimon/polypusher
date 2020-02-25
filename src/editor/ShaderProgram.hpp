#pragma once

#include <string>

class ShaderProgram final
{
public:
  ShaderProgram(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
  ~ShaderProgram();

  unsigned int getProgram() const;

private:
  static inline constexpr auto infoLogSize = 512;

  unsigned int program;

  void compileShader(unsigned int shader, const char* data) const;
};