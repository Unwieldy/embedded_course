
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include <iostream>

// This callback is executed every time the timer expires
bool timer_callback(struct repeating_timer *rt) {
    std::cout << "tick" << std::endl;
    return true;
}

int main() {
    stdio_init_all();

    struct repeating_timer timer;

    if (!add_repeating_timer_ms(1000, timer_callback, nullptr, &timer)) {
        std::cout << "Failed to add repeating timer!\n";
    }

    while (true) {
        // Sleep for a period, the work is done in the timer callback.
        sleep_ms(2000);
    }

    return 0;
}

