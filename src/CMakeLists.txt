set(
        LIB_SRC
        utilities.cpp
        )
add_library( game_lib SHARED ${LIB_SRC})

set(
        EXE_SRC
        main.cpp
        )

add_executable(game ${EXE_SRC})
target_link_libraries(game game_lib gcov sfml-graphics sfml-window sfml-system sfml-audio)

if (ENABLE_COVERAGE)
    add_compile_options(-g -O0)
    add_compile_options(-fprofile-arcs -ftest-coverage)
endif()
