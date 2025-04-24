cmake_minimum_required(VERSION 3.13)

set(exec ultrasound)

# Create the executable
add_executable(${exec} main.cpp)

# Link the necessary libraries
target_link_libraries(${exec}
	pico_stdlib
)

pico_add_extra_outputs(${exec})

pico_enable_stdio_uart(${exec} 1)
