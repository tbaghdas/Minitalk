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

void	ft_send(char *str, pid_t pid_serv)
{
	int		mask;
	int 	i;
	int		j;
	float	delay;

	i = 0;
	delay = 0.0001;
	mask = 1;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if(str[i] & (mask << j))
			{
				kill(pid_serv, SIGUSR1);
			}
			sleep(delay);
			j++;
		}
		i++;
	}
	sleep(delay * 8);
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
    pid = itoa(getpid());
    printf("The process ID is: %s\n", pid);
    //printf("Press Ctrl+C to interrupt\n");

	pid_serv = atoi(argv[1]);
	ft_send(pid, pid_serv);
	ft_send(argv[2], pid_serv);

    return 0;
}
