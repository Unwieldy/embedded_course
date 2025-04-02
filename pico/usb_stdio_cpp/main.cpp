#include "pico/stdlib.h"
#include <iostream>
#include <cstring>

int main() {
    stdio_init_all();

    while (true) {
        std::cout << "Enter something: ";
        std::string input;
        if (std::cin >> input) {
            std::cout << "Received: " << input << std::endl;
        } else {
            std::cerr << "getline failed" << std::endl;
        }

    }
    return 0;
}

