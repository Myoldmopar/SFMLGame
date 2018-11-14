cmake_minimum_required(VERSION 3.9)
project(Lesson1)
set(CMAKE_CXX_STANDARD 17)

# our cmake options
set(CMAKE_BUILD_TYPE Debug)
option(BUILD_TESTING "Build testing targets" ON)
option(ENABLE_COVERAGE "Enable code coverage checking" ON)

# other cmake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# common include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Build the main tool
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Build testing
if (BUILD_TESTING)
    set(BUILD_GTEST ON CACHE BOOL "" FORCE)
    add_subdirectory(third_party/gtest)
    add_subdirectory(test)
endif()
