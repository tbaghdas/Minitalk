#include "minitalk.h"

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	val;
	static char				count;

	(void)context;
	if (signal == SIGUSR1)
	{
		val <<= 1;
		val++;
		count++;
	}
	else if (signal == SIGUSR2)
	{
		val <<= 1;
		count++;
	}
	if (count > 7)
	{
		write(1, &val, 1);
		val = 0;
		count = 0;
	}
	kill(info->si_pid, signal);
}

void	ft_putpid(int n)
{
	long	nb;
	long	div;
	char	c;

	write(1, "The process ID is: ", 19);
	nb = n;
	div = 10;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while (nb / (div * 10))
	{
		div *= 10;
	}
	while (div > 2 && nb > 9)
	{
		c = (nb / div) % 10 + '0';
		write(1, &c, 1);
		div /= 10;
	}
	c = (nb % 10) + '0';
	write(1, &c, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putpid(getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) == -1)
	{
		write(1, "ERROR: sigemptyset\n", 19);
		return (1);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(1, "ERROR: SIGUSR1\n", 15);
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(1, "ERROR: SIGUSR2\n", 15);
		return (1);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
