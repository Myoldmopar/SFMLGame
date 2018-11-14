cmake_minimum_required(VERSION 3.10)
project(Lesson1)

set(CMAKE_CXX_STANDARD 17)

set(SRC
  src/main.cpp
)

add_executable(Lesson1 ${SRC})
target_link_libraries(Lesson1 sfml-graphics sfml-window sfml-system)
