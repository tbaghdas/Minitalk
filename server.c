#include "minitalk.h"

#include <sys/time.h>
int	g_str = 0;

void	sigint_handler(int sig)
{
	int	val;

	if (g_str > 32767)
	{
		val = g_str;
		g_str = 0;
		printf("KLKL\n");
		ft_write(val);
		// g_str = 0;
	}
	if (sig == SIGUSR1)
	{
		g_str <<= 1;
		g_str++;

	}
	else if (sig == SIGUSR2)
	{
		g_str <<= 1;
	}
}

void	ft_write(int val)
{
	char	c = 0;
	static	pid_t pid_client;

	// c = g_str & 1 | (g_str & 4) >> 1 | (g_str & 16) >> 2 | (g_str & 64) >> 3 | (g_str & 256) >> 4 | (g_str & 1024) >> 5 | (g_str & 4096) >> 6 | (g_str & 16384) >> 7;
	c = (val & 1) << 7 | (val & 4) << 4 | (val & 16) << 1 | (val & 64) >> 2 | (val & 256) >> 5 | (val & 1024) >> 8 | (val & 4096) >> 11 | (val & 16384) >> 14;
	// write(1, "1", 1);
	if (c != 0)
		printf("%u  %d\n", c, val);
	if (pid_client != 0)
	{
		//kill(pid_client, SIGUSR1);
	}
	else
	{
		pid_client = c;
	}
	// if (kill(pid, SIGUSR2) == -1)/////////////////////////////////////////////////////////////////////////////////////////////////////
				// ft_error_handler(0);
}

int	main(void)
{
	float	delay;
	pid_t	pid;

	delay = 1;
	if (signal(SIGUSR1, sigint_handler) == SIG_ERR)
	{
		// perror("signal");
		return (1);
	}
	if (signal(SIGUSR2, sigint_handler) == SIG_ERR)
	{
		// perror("signal");
		return (1);
	}
	pid = getpid();
	printf("The process ID is: %d\n", pid);
	while (1)
	{
		// g_str <<= 1;
		// g_str += 2;
		// sleep(delay);
		// if (g_str > 32767)
		// {
		// 	 printf("KLKL\n");
		// 	ft_write();
		// 	g_str = 0;
		// }
	}
	return (0);
}
