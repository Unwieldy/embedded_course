cmake_minimum_required(VERSION 3.13)

# Create the executable
add_executable(gpio_irq gpio_irq.cpp)

# Link the necessary libraries
target_link_libraries(gpio_irq
	pico_stdlib
	hardware_gpio
)

pico_add_extra_outputs(gpio_irq)


# Create the executable
add_executable(timer_irq timer_irq.cpp)

# Link the necessary libraries
target_link_libraries(timer_irq
	pico_stdlib
	hardware_gpio
)

pico_add_extra_outputs(timer_irq)
