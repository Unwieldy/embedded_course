/*
 * HC‑SR04 connections:
 *    TRIG → GPIO16
 *    ECHO → GPIO17
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/timer.h"


// HC‑SR04 Definitions
#define TRIG_PIN 16
#define ECHO_PIN 17

// This function sends a 10us pulse and measures the echo time in microseconds.
// It times out after ~30ms.
uint64_t measure_distance_us() {
    gpio_put(TRIG_PIN, 0);
    sleep_us(2);
    gpio_put(TRIG_PIN, 1);
    sleep_us(10);
    gpio_put(TRIG_PIN, 0);

    absolute_time_t start_time = get_absolute_time();
    while (gpio_get(ECHO_PIN) == 0) {
        if (absolute_time_diff_us(start_time, get_absolute_time()) > 30000) {
            return 0;  // timeout
        }
    }
    absolute_time_t pulse_start = get_absolute_time();

    while (gpio_get(ECHO_PIN) == 1) {
        if (absolute_time_diff_us(pulse_start, get_absolute_time()) > 30000) {
            break;  // safety timeout
        }
    }
    absolute_time_t pulse_end = get_absolute_time();
    uint64_t pulse_width = absolute_time_diff_us(pulse_start, pulse_end);

    return pulse_width;
}


float pulse_us_to_cm(uint64_t pulse_us) {
    // Distance(cm) = pulse_us / 58.0 (approximation)
    return pulse_us / 58.0f;
}

int main() {
    stdio_init_all();

    // Initialize HC‑SR04 pins
    gpio_init(TRIG_PIN);
    gpio_set_dir(TRIG_PIN, GPIO_OUT);
    gpio_init(ECHO_PIN);
    gpio_set_dir(ECHO_PIN, GPIO_IN);

    while (true) {
        uint64_t pulse = measure_distance_us();

        float distance = (pulse > 0) ? pulse_us_to_cm(pulse) : 0.0f;

	      printf("%.2f cm\n", distance);

        sleep_ms(200);
    }

    return 0;
}


