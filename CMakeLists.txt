cmake_minimum_required(VERSION 3.20)
project(Physics_Sim C)

set(CMAKE_C_STANDARD 11)

add_executable(sim
        src/main.c
        src/physics.c
        src/render.c
        src/demos.c
        include/rigidbody.h
        src/rigidbody.c
        include/world.h
)

add_library(raylib STATIC IMPORTED)
set_target_properties(raylib PROPERTIES
        IMPORTED_LOCATION /usr/local/lib/libraylib.a
)

target_include_directories(sim PRIVATE include /usr/local/include)
target_link_libraries(sim raylib GL m pthread dl rt X11)