#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <iostream>

// Define the pins for the button and LED
#define BUTTON_PIN 17
#define LED_PIN 16
#define DEBOUNCE_TIME_MS 200

volatile uint32_t last_interrupt_time = 0;

// Interrupt Service Routine for button press
void gpio_callback(uint gpio, uint32_t events) {
    uint32_t current_time = to_ms_since_boot(get_absolute_time());

    if (current_time - last_interrupt_time > DEBOUNCE_TIME_MS) {
	last_interrupt_time = current_time;
	std::cout << "Button pressed at " << current_time << std::endl;
	bool led_on = gpio_get(LED_PIN);
	gpio_put(LED_PIN, !led_on);
    }
}

int main() {
    // Initialize chosen GPIO pins
    stdio_init_all();  // Optionally initialize USB serial for debugging

    // Set up the LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    // Set up the button
    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    // Set the interrupt handler for the button
    // The callback handles all GPIO interrupts, so check the pin in the function.
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_RISE, true, gpio_callback);

    while (true) {
	sleep_ms(100);
    }

    return 0;
}
