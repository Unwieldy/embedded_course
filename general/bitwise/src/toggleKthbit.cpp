#include <iostream>

int toggleKthBit(int num, int k) {
    return num ^ (1 << k);
}

int main() {
    int num, k;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Enter the bit position to toggle (0-based): ";
    std::cin >> k;

    std::cout << "New number after toggling: " << toggleKthBit(num, k) << std::endl;
    return 0;
}

