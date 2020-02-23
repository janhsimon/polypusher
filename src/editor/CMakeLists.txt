set(HEADER_FILES
  Application.hpp
  Renderer.hpp
  Shader.hpp
  Vertex.hpp
  Window.hpp
)

set(SOURCE_FILES
  Application.cpp
  Renderer.cpp
  Shader.cpp
  Vertex.cpp
  Window.cpp
)

add_executable(editor ${HEADER_FILES} ${SOURCE_FILES})

set_property(TARGET editor PROPERTY CXX_STANDARD 17)
target_compile_definitions(editor PRIVATE GLFW_INCLUDE_NONE) # glad handles this, avoid conflict
include_directories("../../external/glad/include" "../../external/glfw-3.3.2/include")
target_link_libraries(editor glad glfw glm)