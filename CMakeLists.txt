cmake_minimum_required(VERSION 3.9)
project(Lesson1)
set(CMAKE_CXX_STANDARD 17)

# common include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Build the main tool
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Build testing
option( BUILD_TESTING "Build testing targets" ON )
if (BUILD_TESTING)
    set(BUILD_GTEST ON CACHE BOOL "" FORCE)
    add_subdirectory(third_party/gtest)
    add_subdirectory(test)
    include(CTest)
endif()
