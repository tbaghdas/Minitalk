#include "minitalk.h"

int	g_count = 0;

void sigint_handler(int sig) {
	if (sig == SIGUSR1)
	{
		g_count++;
	}
    printf("Caught signal %d\n", sig);
    exit(0);
}
int	ft_check_digit(char *str)
{
	while (*str != '\0')
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
	delay = 0.2;
	mask = 1;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			kill(pid_serv, SIGUSR1);
			 printf("SIGUSR1 clock , j-%d\n", j);
			sleep(delay);
			if(str[i] & (mask << j))
			{
				kill(pid_serv, SIGUSR1);
				 write(1, "1\n", 2);
			}
			else
			{
				kill(pid_serv, SIGUSR2);
				 write(1, "2\n", 2);
			}
			sleep(delay);
			j++;
		}
		i++;
		sleep(delay * 8);
	}
}


int main(int argc, char** argv)
{
    if (signal(SIGUSR1, sigint_handler) == SIG_ERR) {
        // perror("signal");
        return 1;
    }    
	// if (signal(SIGUSR2, sigint_handler) == SIG_ERR) {
    //     // perror("signal");
    //     return 1;
    // }
	char	*pid;
	pid_t 	pid_serv;
	int 	i;
	int		j;
	int		mask;

	if (argc != 3 || ft_check_digit(argv[1]) == 1)
	{
		write(1, "Wrong arguments!", 16);
		return (1);
	}
    pid = ft_itoa(getpid());
    printf("The process ID is: %s\n", pid);

	pid_serv = atoi(argv[1]);
	// ft_send(pid, pid_serv);
	ft_send(argv[2], pid_serv);
	if (ft_strlen(argv[2]) == g_count)
	{
		write(1, "The message has been passed successfully", 40);
	}
    return 0;
}
