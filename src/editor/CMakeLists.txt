set(HEADER_FILES
  Window.hpp
)

set(SOURCE_FILES
  Main.cpp
  Window.cpp
)

add_executable(editor ${HEADER_FILES} ${SOURCE_FILES})

set_property(TARGET editor PROPERTY CXX_STANDARD 17)
include_directories("../../external/glad/include" "../../external/glfw-3.3.2/include")
target_link_libraries(editor glad glfw)