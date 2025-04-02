cmake_minimum_required(VERSION 3.13)

# Set the PICO_BOARD variable
set(PICO_BOARD pico_w)

# Include the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Define the project
project(irq C CXX ASM)

# Initialize the Pico SDK
pico_sdk_init()

add_subdirectory(src)
