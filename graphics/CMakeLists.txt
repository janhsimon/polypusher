set(HEADER_FILES
  include/graphics/Batch.hpp
  include/graphics/Renderer.hpp
  include/graphics/ShaderProgram.hpp
  include/graphics/Vertex.hpp
)

set(SOURCE_FILES
  src/Batch.cpp
  src/Renderer.cpp
  src/ShaderProgram.cpp
  src/Vertex.cpp
)

add_library(graphics STATIC ${HEADER_FILES} ${SOURCE_FILES})

set_property(TARGET graphics PROPERTY CXX_STANDARD 17)
target_include_directories(graphics PRIVATE "include/graphics" "../external/glad/include")
target_link_libraries(graphics glad glm)