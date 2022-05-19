/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:44:55 by sbombadi          #+#    #+#             */
/*   Updated: 2022/01/26 20:15:52 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(const char *str)
{
	int	z;
	int	num;

	z = 1;
	num = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		z = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * z);
}

void	do_kill(int pid, int *mass)
{
	int	i;

	i = 0;
	while (i != 8)
	{
		if (mass[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		i++;
	}
}

void	send(unsigned char c, int pid)
{
	int	i;
	int	mass[8];

	i = 0;
	if (c == '\0')
	{
		while (i < 8)
		{
			kill(pid, SIGUSR2);
			usleep(1000);
			i++;
		}
	}
	while (c > 0)
	{
		if (c % 2 == 1)
			mass[7 - i] = 1;
		else
			mass[7 - i] = 0;
		c /= 2;
		i++;
	}
	do_kill(pid, mass);
}

void	client_handler(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("Signal accepted\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;
	int					pid;
	int					i;

	i = 0;
	(void)argc;
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = &client_handler;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (argv[2][i])
	{
		send(argv[2][i], pid);
		i++;
	}
	send('\0', pid);
	while (42)
		pause();
}
