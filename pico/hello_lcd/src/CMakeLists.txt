cmake_minimum_required(VERSION 3.13)

set(exec basic_lcd)
# Create the executable
add_executable(${exec} main.cpp)

# Link the necessary libraries
target_link_libraries(${exec}
	pico_stdlib
	hardware_i2c
)

pico_add_extra_outputs(${exec})
