#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Caught signal %d\n", sig);
    // Add cleanup code here if needed
    //exit(0); // Or use longjmp to return to previous location
}

int main() 
{
	int	start;

	start = 0;
    if (signal(SIGUSR1, sigint_handler) == SIG_ERR) {
        perror("signal");
        return 1;
    }
	pid_t pid;

    pid = getpid();
    printf("The process ID is: %d\n", pid);
    printf("Press Ctrl+C to interrupt\n");

    while (1) {
        // Program continues executing
    }

    return 0;
}
