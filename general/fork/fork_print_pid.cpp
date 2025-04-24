#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	std::cout << "Starting the program. PID: " << getpid() << "\n";

	pid_t pid = fork();

	if (pid < 0) {
		// Fork failed
		std::cerr << "Fork failed!\n";
		return 1;
	}
	if (pid == 0) {
		// Child process

		auto my_pid = getpid();	
		auto parent_pid = getppid();
		std::cout << "[Child] Hello! I'm the child process. PID: " << my_pid << "\n";
		std::cout << "[Child] My parent's PID: " << parent_pid << "\n";

		std::cout << "[Child] Finished work. Exiting...\n";
		return 0;
	} else {
		// Parent process
		auto my_pid = getpid();
		std::cout << "[Parent] I'm the parent. PID: " << my_pid << "\n";
		std::cout << "[Parent] I created a child with PID: " << pid << "\n";

		// Wait for the child to finish
		int status;
		waitpid(pid, &status, 0);

		std::cout << "[Parent] Child has finished. Status: " << status << "\n";
		std::cout << "[Parent] Exiting...\n";
	}

	return 0;
}

