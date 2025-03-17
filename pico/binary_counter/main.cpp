#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_COUNT 8 // Number of LEDs
#define LED_START_PIN 4 // Starting GPIO pin for LEDs

int main() {
    // Initialize the standard I/O
    stdio_init_all();

    // Create a mask for the GPIO pins to be initialized
    uint32_t led_mask = (1 << LED_COUNT) - 1;

    // Apply the offset to the mask
    uint32_t offset_mask = led_mask << LED_START_PIN; // Adjusted mask with the starting pin offset

    // Initialize the chosen GPIO pins as outputs
    gpio_init_mask(offset_mask); // Initialize the pins starting from LED_START_PIN
    gpio_set_dir_masked(offset_mask, offset_mask); // Set the direction of the pins to output

    uint32_t counter = 0; // Initialize the counter

    while (true) {
        // Set the GPIO pins according to the counter value
        gpio_put_masked(offset_mask, (counter & led_mask) << LED_START_PIN); // Set pins according to the counter

        // Increment the counter and wrap it using modulus
        counter = (counter + 1) % (1 << LED_COUNT); // Wrap around using modulus

        sleep_ms(500); // Wait for 500 milliseconds
    }

    return 0;
}
