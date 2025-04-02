#include <iostream>

bool isPowerOfTwo(int num) {
    return (num > 0) && ((num & (num - 1)) == 0);
}

int main() {
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    if (isPowerOfTwo(num))
        std::cout << num << " is a power of 2" << std::endl;
    else
        std::cout << num << " is not a power of 2" << std::endl;

    return 0;
}

