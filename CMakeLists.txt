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

### Build the main tool
# First create a list of all the source files **except** the main function
set(SRC_NOT_MAIN
        include/config.hpp
        include/utilities.hpp
        src/config.cpp
        src/utilities.cpp
)
# Create a copy of this list
set(EXE_SRC ${SRC_NOT_MAIN})
# Then append the main function to it
list(APPEND EXE_SRC
        src/main.cpp
)
# Build the main program based on this list
add_executable(game ${EXE_SRC})
target_link_libraries(game gcov sfml-graphics sfml-window sfml-system sfml-audio)

# Build testing
if (BUILD_TESTING)
    include(GoogleTest)
    set(BUILD_GTEST ON CACHE BOOL "" FORCE)
    add_subdirectory(third_party/gtest)
    # Create a copy of the original *not main* list
    set(TEST_SRC ${SRC_NOT_MAIN})
    list(APPEND TEST_SRC
            test/src/test_config.cpp
            test/src/test_utilities.cpp
            test/src/test.cpp
    )
    add_executable(game_tests ${TEST_SRC})
    if(ENABLE_COVERAGE)
        set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} --coverage")
        set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
    endif()
    target_link_libraries(game_tests gcov gtest)
endif()
