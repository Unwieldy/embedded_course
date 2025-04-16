cmake_minimum_required(VERSION 3.10)
project(HelloLib)

set(CMAKE_C_STANDARD 23)

set(OUTPUT_DIR ${PROJECT_SOURCE_DIR}/output)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/bin)

add_library(hello_static STATIC src/hellolib.c)
add_library(hello_shared SHARED src/hellolib.c)

set_target_properties(hello_static PROPERTIES OUTPUT_NAME hello)
set_target_properties(hello_shared PROPERTIES OUTPUT_NAME hello)

target_include_directories(hello_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(hello_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)


