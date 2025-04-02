// Solution to Count the Number of 1s in a Binary Representation


#include <iostream>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;  // Check last bit
        num >>= 1;         // Shift right
    }
    return count;
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::cout << "Number of set bits: " << countSetBits(num) << std::endl;
    return 0;
}

