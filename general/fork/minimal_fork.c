#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	pid_t pid = fork();

	if (pid < 0) {
		// Error
	}
	if (pid == 0) {
		// Child process
        printf("Child process.\n");
	} else {
		// Parent process
        printf("Parent process.\n");
	}

	return 0;
}

