cmake_minimum_required(VERSION 3.10)
project(MyApp)

set(CMAKE_C_STANDARD 23)

add_executable(my_app main.cpp)


# ---- STATIC LIB EXAMPLE ----
add_library(hello STATIC IMPORTED)
set_target_properties(hello PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/libhello.a"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libs/include"
)

# ---- OR SHARED LIB EXAMPLE ----
# add_library(hellolib SHARED IMPORTED)
# set_target_properties(hellolib PROPERTIES
#     IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/libs/libhello.so"
#     INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}/libs/include"
# )

target_link_libraries(my_app PRIVATE hello)


