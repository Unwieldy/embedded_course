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


# Create the executable
add_executable(blink_irq blink_irq.cpp)

# Link the necessary libraries
target_link_libraries(blink_irq
	pico_stdlib
	hardware_gpio
)

# Enable USB and UART for the executable
pico_enable_stdio_usb(blink_irq 0)
pico_enable_stdio_uart(blink_irq 1)


pico_add_extra_outputs(blink_irq)
