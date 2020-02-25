set(HEADER_FILES
  src/Application.hpp
  src/Renderer.hpp
  src/ShaderProgram.hpp
  src/Vertex.hpp
  src/Window.hpp
)

set(SOURCE_FILES
  src/Application.cpp
  src/Renderer.cpp
  src/ShaderProgram.cpp
  src/Vertex.cpp
  src/Window.cpp
)

add_executable(editor ${HEADER_FILES} ${SOURCE_FILES})

set_property(TARGET editor PROPERTY CXX_STANDARD 17)
target_compile_definitions(editor PRIVATE GLFW_INCLUDE_NONE) # glad handles this, avoid conflict
include_directories("../external/glad/include" "../external/glfw-3.3.2/include")
target_link_libraries(editor glad glfw glm)