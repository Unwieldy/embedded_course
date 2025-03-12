#include "pico/stdlib.h"
#include <stdio.h>

bool is_button_pressed(uint pin) {
    return !gpio_get(pin);
}

void toggle(uint btn, uint led) {
    static bool led_state = false;
    if (is_button_pressed(btn)) {
        led_state = !led_state;
        gpio_put(led, led_state);
    }
}

int main() {
    stdio_init_all();
    
    const uint LED_PIN = 16;
    const uint BUTTON_PIN = 17;

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    while (true) {
        toggle(BUTTON_PIN, LED_PIN);
        sleep_ms(100);
    }
}

