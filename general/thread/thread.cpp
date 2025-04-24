#include <thread>
#include <unistd.h>
#include <iostream>
#include <string>

void count(const std::string &who)
{
	for (auto i = 0; i < 10; i++)
	{
		std::cout << "Count["<< who << "]: " << i << std::endl;
		sleep(1);
	}
}

int main() {
    std::thread t([]{ count("thread"); });

    count("main");
    
    t.join(); // Wait for the thread to finish
    return 0;
}
