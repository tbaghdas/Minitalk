#include "../minitalk.h"

long	ft_atoi(const char *s)
{
	long	res;
	long	i;
	long	sign;

	res = 0;
	i = 0;
	sign = 1;
	if (s[i] < 0)
		return (res);
	while (s[i] && (s[i] == 32 || (s[i] >= 9 && s[i] <= 13)))
		i++;
	if (s[i] == 45 || s[i] == 43)
	{
		if (s[i] == 45)
			sign *= -1;
		i++;
	}
	while (s[i] > 47 && s[i] < 58)
		res = res * 10 + s[i++] - '0';
	return (res * sign);
}
