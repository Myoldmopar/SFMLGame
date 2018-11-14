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
target_link_libraries(game game_lib gcov sfml-graphics sfml-window sfml-system)

if (BUILD_TESTING)
    add_compile_options(-g -O0 -fprofile-arcs -ftest-coverage)
    set(LINKER_FLAGS "${LINKER_FLAGS} --coverage")
endif()
