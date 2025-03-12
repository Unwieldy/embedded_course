#include <stdio.h>
#include <pico/stdlib.h>

int main() {
    stdio_init_all();

    sleep_ms(5000);

    while (true) {
        char input[100];
        if (scanf("%99s", input) == 1) {
            printf("Received: %s\n", input); // Echo the input back to the host
        }
    }

    return 0;
}
