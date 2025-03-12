#include "pico/stdlib.h"
#include <stdio.h>

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
        if (gpio_get(BUTTON_PIN) == 0) {
            gpio_put(LED_PIN, 1);
            printf("high\n");
        } else {
            gpio_put(LED_PIN, 0);
            printf("low\n");
        }
        sleep_ms(10);
    }
}

