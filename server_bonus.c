/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:49:25 by sbombadi          #+#    #+#             */
/*   Updated: 2022/01/26 19:45:38 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int act, siginfo_t *t, void *tmp)
{
	static int	c;
	static int	bit;
	int			b;

	(void)tmp;
	if (act == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
			kill(t->si_pid, SIGUSR2);
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
		act = 0;
	}
	kill(t->si_pid, SIGUSR1);
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = &handler;
	if (argc == 1)
	{
		ft_printf("PID: %d\n", getpid());
		while (5)
		{
			sigaction(SIGUSR1, &action, NULL);
			sigaction(SIGUSR2, &action, NULL);
			pause();
		}
	}
	return (0);
}
