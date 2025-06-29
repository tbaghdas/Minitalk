#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>
# include <unistd.h>

void	sigint_handler(int sig);
int		ft_check_digit(char *str);
void	ft_sender(char b, pid_t pid_serv);
void	ft_send(char *str, pid_t pid_serv);
void	sig_handler(int signal, siginfo_t *info, void *context);
void	ft_putpid(int n);
long	ft_atoi(const char *s);

#endif