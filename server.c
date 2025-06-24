#include "minitalk.h"

#include <sys/time.h>
int	g_str = 1;

void	sigint_handler(int sig)
{
	float	delay;

	// delay = 0.01;
	// printf("Caught signal %d\n", sig);
	// g_str <<= 1;//////////////////////////////////////////////
	g_str++;
	write(1, "1", 1);
	// struct timeval tv;
	// gettimeofday(&tv, NULL);
	// printf("time %d\n", tv.tv_usec);
	// sleep(delay);///////////////////////////////////////////////////////////////////////////
}


void	ft_write()
{
	char	c;

	c = g_str & 1 | (g_str & 4) << 1 | (g_str & 16) << 2 | (g_str & 64) << 3 | (g_str & 256) << 4 | (g_str & 1024) << 5 | (g_str & 4096) << 6 | (g_str & 16384) << 7;
	// write(1, "1", 1);
	if (c != 0)
	printf("%d  %d\n", c, g_str);
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
	pid = getpid();
	printf("The process ID is: %d\n", pid);
	while (1)
	{
		g_str <<= 1;
		// g_str += 2;
		sleep(delay);
		if (g_str > 32767)
		{
			// printf("KLKL\n");
			ft_write();
			g_str = 0;
		}
	}
	return (0);
}
