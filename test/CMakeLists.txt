include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

include(GoogleTest)
include(CodeCoverage)

set(
        test_src
        src/test_utilities.cpp
        src/test_main.cpp
)

add_executable(game_tests ${test_src})
add_definitions(--coverage)
target_link_libraries(game_tests gtest game_lib)
gtest_add_tests(
        TARGET      game_tests
        TEST_SUFFIX .noArgs
        TEST_LIST   noArgsTests
)

set(COVERAGE_LCOV_EXCLUDES '/usr/*' '*gtest/*')
setup_target_for_coverage_lcov(NAME game_coverage EXECUTABLE game_tests)
