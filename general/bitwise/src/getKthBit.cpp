// Extract the K-th bit of a number

#include <iostream>

int getKthBit(int num, int k) {
    return (num >> k) & 1;
}

int main() {
    int num, k;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Enter the bit position (0-based): ";
    std::cin >> k;

    std::cout << "The " << k << "-th bit is: " << getKthBit(num, k) << std::endl;
    return 0;
}

