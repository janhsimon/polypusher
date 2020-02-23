project(external)

add_subdirectory(glad)
set_target_properties(glad PROPERTIES FOLDER "external")

add_subdirectory(glfw)
set_target_properties(glfw PROPERTIES FOLDER "external")

add_subdirectory(glm)