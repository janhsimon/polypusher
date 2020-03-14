project(external)

# glad
add_subdirectory(glad)
set_target_properties(glad PROPERTIES FOLDER "external")

# glfw
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
add_subdirectory(glfw)
set_target_properties(glfw PROPERTIES FOLDER "external")

# glm
add_subdirectory(glm)