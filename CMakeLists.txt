cmake_minimum_required(VERSION 3.1)
project(Polypusher)

add_subdirectory(editor)
add_subdirectory(external)
add_subdirectory(graphics)
add_subdirectory(interface)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT editor)