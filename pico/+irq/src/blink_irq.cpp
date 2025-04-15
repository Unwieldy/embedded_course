#include "pico/stdlib.h"
#include <iostream>

#define LED_PIN 16
#define DELAY 200

bool blink(repeating_timer_t *rt) {
	auto led_state = gpio_get(LED_PIN);
	gpio_put(LED_PIN, !led_state);
	return true;
}

int main()
{
	gpio_init(16);
	gpio_set_dir(16, 1);

	repeating_timer_t timer;

	if(!add_repeating_timer_ms(DELAY, &blink, nullptr, &timer))
	{
		std::err << "error" <<std::endl;
	}


	while(1) {
		sleep_ms(1000);
	}

	return 0;
}
