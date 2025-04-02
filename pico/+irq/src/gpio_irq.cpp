#include "pico/stdlib.h"
#include "hardware/gpio.h"

// Define the pins for the button and LED
#define BUTTON_PIN 17
#define LED_PIN 16

// Interrupt Service Routine for button press
void gpio_callback(uint gpio, uint32_t events) {
    bool led_on = gpio_get(LED_PIN);
    gpio_put(LED_PIN, !led_on);
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
    gpio_set_irq_enabled_with_callback(BUTTON_PIN, GPIO_IRQ_EDGE_FALL, true, &gpio_callback);

    while (true) {
        tight_loop_contents();
    }

    return 0;
}
