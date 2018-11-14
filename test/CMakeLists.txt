INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR} )

include(GoogleTest)

set(
        test_src
        src/test_utilities.cpp
        src/test_main.cpp
)

add_executable(game_tests ${test_src})
target_link_libraries(game_tests gtest game_lib)
gtest_add_tests(
        TARGET      game_tests
        TEST_SUFFIX .noArgs
        TEST_LIST   noArgsTests
)
