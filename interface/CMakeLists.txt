set(HEADER_FILES
  include/interface/Button.hpp
  include/interface/MainWindow.hpp
)

set(SOURCE_FILES
  src/Button.cpp
  src/MainWindow.cpp
)

add_library(interface STATIC ${HEADER_FILES} ${SOURCE_FILES})

set_property(TARGET interface PROPERTY CXX_STANDARD 17)
target_compile_definitions(interface PRIVATE GLFW_INCLUDE_NONE) # avoid conflict between glfw and glad
target_include_directories(interface PRIVATE "include/interface" "../graphics/include" "../external/glad/include" "../external/glfw/include")
target_link_libraries(interface graphics glad glfw)