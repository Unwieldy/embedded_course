#include "pico/stdlib.h"
#include "pico/rand.h"
#include "hardware/gpio.h"

#define LED_COUNT 10 // Number of LEDs
#define LED_START_PIN 0 // Starting GPIO pin for LEDs

int main() {
	// Initialize the standard I/O
	stdio_init_all();
	auto rand = get_rand_32();

	// Create a mask for the GPIO pins to be initialized
	uint32_t led_mask = (1 << LED_COUNT) - 1;

	// Apply the offset to the mask
	uint32_t offset_mask = led_mask << LED_START_PIN; // Adjusted mask with the starting pin offset

	// Initialize the chosen GPIO pins as outputs
	gpio_init_mask(offset_mask); // Initialize the pins starting from LED_START_PIN
	gpio_set_dir_masked(offset_mask, offset_mask); // Set the direction of the pins to output

	while (true) {
		rand = get_rand_32();
		// Set the GPIO pins according to the counter value
		gpio_put_masked(offset_mask, rand << LED_START_PIN); // Set pins according to the counter

		sleep_ms(200); // Wait for 500 milliseconds
	}

	return 0;
}

