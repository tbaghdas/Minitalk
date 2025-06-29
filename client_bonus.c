#include "minitalk.h"

int	g_num = 0;

void	sigint_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		g_num = 10;
	}
	if (sig == SIGUSR2)
	{
		g_num = 12;
	}
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

void	ft_sender(char b, pid_t pid_serv)
{
	if (b == 1)
	{
		if (kill(pid_serv, SIGUSR1) == -1)
		{
			write(1, "ERROR: Failed to send signal 1 to server\n", 41);
			exit(1);
		}
		pause();
		if (g_num != 10)
		{
			write(1, "ERROR: Failed to send signal 1 to server\n", 41);
			exit(1);
		}
		g_num = 0;
		return ;
	}
	pause();
	if (g_num != 12)
	{
		write(1, "ERROR: Failed to send signal 2 to server\n", 41);
		exit(1);
	}
	g_num = 0;
}

void	ft_send(char *str, pid_t pid_serv)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j > -1)
		{
			if (str[i] & (1 << j))
				ft_sender(1, pid_serv);
			else
			{
				if (kill(pid_serv, SIGUSR2) == -1)
				{
					write(1, "ERROR: Failed to send signal 2 to server\n", 41);
					exit(1);
				}
				ft_sender(0, pid_serv);
			}
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_serv;

	if (signal(SIGUSR1, sigint_handler) == SIG_ERR)
	{
		write(1, "ERROR: SIGUSR1\n", 15);
		return (1);
	}
	if (signal(SIGUSR2, sigint_handler) == SIG_ERR)
	{
		write(1, "ERROR: SIGUSR2\n", 15);
		return (1);
	}
	if (argc != 3 || ft_check_digit(argv[1]) == 1)
	{
		write(1, "Wrong arguments!\n", 17);
		return (1);
	}
	pid_serv = ft_atoi(argv[1]);
	ft_send(argv[2], pid_serv);
	write(1, "The message has been passed successfully\n", 41);
	return (0);
}
