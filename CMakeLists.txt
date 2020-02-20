cmake_minimum_required(VERSION 3.1)
project(Polypusher)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT editor)

add_subdirectory(src)
add_subdirectory(external)