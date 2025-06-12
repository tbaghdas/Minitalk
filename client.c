#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(int sig) {
    printf("Caught signal %d\n", sig);
    // Add cleanup code here if needed
    exit(0); // Or use longjmp to return to previous location
}
int	ft_check_digit(char *str)
{
	while (*str != NULL)
	{
		if (*str < '0' || *str > '9')
		{
			return (1);
		}
		str++;
	}
	return (0);
}


int main(int argc, char** argv) {
    // if (signal(SIGINT, sigint_handler) == SIG_ERR) {
    //     perror("signal");
    //     return 1;
    // }
	pid_t 	pid;
	pid_t 	pid_serv;
	int 	i;
	int		j;
	int		mask;

	if (argc != 3 || ft_check_digit(argv[1]) == 1)
	{
		write(1, "Wrong arguments!", 16);
		return (1);
	}
    pid = getpid();
    printf("The process ID is: %d\n", pid);
    //printf("Press Ctrl+C to interrupt\n");

	pid_serv = atoi(argv[1]);
	i = 0;
	//j = 0;
	mask = 1;
	while (argv[2][i] != '\0')
	{
		//SIGUSR1 = i;
		j = 0;
		while (j < 8)
		{
			if(argv[2][i] & (mask << j))
			{
				kill(pid_serv, SIGUSR1);
			}
			sleep(0.0001);
			j++;
		}
		i++;
	}
		// while (1) {
    //     // Program continues executing
    // }

    return 0;
}
