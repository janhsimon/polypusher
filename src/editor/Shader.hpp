#pragma once

#include <string>

class Shader final
{
public:
  Shader(const std::string& source, unsigned int program, unsigned int type);
  ~Shader();

private:
  static inline constexpr auto infoLogSize = 512;

  unsigned int shader;
};