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
target_link_libraries(game game_lib sfml-graphics sfml-window sfml-system)

