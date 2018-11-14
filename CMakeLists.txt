cmake_minimum_required(VERSION 3.10)
project(Lesson1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lesson1 main.cpp)
target_link_libraries(Lesson1 sfml-graphics sfml-window sfml-system)
# set_property(TARGET Lesson1 APPEND_STRING PROPERTY LINK_FLAGS " -lsfml-graphics -lsfml-window -lsfml-system")
# set(CMAKE_EXE_LINKER_FLAGS "-lsfml-graphics -lsfml-window -lsfml-system" CACHE INTERNAL "" FORCE)