include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

include(GoogleTest)

set(
        test_src
        src/test_utilities.cpp
        src/test_main.cpp
)

add_executable(game_tests ${test_src})

if(ENABLE_COVERAGE)
    target_compile_options(game_tests PRIVATE --coverage)
    target_link_libraries(game_tests gcov gtest game_lib)
else()
    target_link_libraries(game_tests gtest game_lib)
endif()
