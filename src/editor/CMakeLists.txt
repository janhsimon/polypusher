add_executable(editor "Main.cpp")
include_directories("../../external/glad/include" "../../external/glfw-3.3.2/include")
target_link_libraries(editor glad glfw)

set_property(TARGET editor PROPERTY CXX_STANDARD 17)