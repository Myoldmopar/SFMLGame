include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

include(GoogleTest)
include(CodeCoverage)

set(
        test_src
        src/test_utilities.cpp
        src/test_main.cpp
)

if(ENABLE_COVERAGE)
    add_compile_options(-fprofile-arcs -ftest-coverage)
endif()

add_executable(game_tests ${test_src})

target_link_libraries(game_tests gtest game_lib)

set(COVERAGE_LCOV_EXCLUDES '/usr/*' '*gtest/*')
setup_target_for_coverage_lcov(NAME game_coverage EXECUTABLE game_tests)
