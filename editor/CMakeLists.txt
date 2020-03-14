set(HEADER_FILES
  src/Application.hpp
)

set(SOURCE_FILES
  src/Application.cpp
)

add_executable(editor ${HEADER_FILES} ${SOURCE_FILES})

set_property(TARGET editor PROPERTY CXX_STANDARD 17)
target_include_directories(editor PRIVATE "../graphics/include" "../interface/include")
target_link_libraries(editor graphics interface)