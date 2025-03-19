cmake_minimum_required(VERSION 3.13)

# Set the PICO_BOARD variable
set(PICO_BOARD pico_w)

# Include the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Define the project
project(blink C CXX ASM)

# Initialize the Pico SDK
pico_sdk_init()

# Create the executable
add_executable(${PROJECT_NAME} main.cpp)

pico_add_extra_outputs(${PROJECT_NAME})

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME}
	pico_stdlib
)
