cmake_minimum_required(VERSION 3.13)

# Set the PICO_BOARD variable
set(PICO_BOARD pico_w)

# Include the Pico SDK
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

# Define the project
project(usb_stdio C CXX ASM)

# Set the C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the Pico SDK
pico_sdk_init()

# Create the executable
add_executable(${PROJECT_NAME} main.c)

# Enable USB and UART for the executable
pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 1)

# Add extra outputs (e.g., UF2 file)
pico_add_extra_outputs(${PROJECT_NAME})

# Link the necessary libraries
target_link_libraries(${PROJECT_NAME}
	pico_stdlib
	pico_cyw43_arch_none
)


