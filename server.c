/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:49:00 by sbombadi          #+#    #+#             */
/*   Updated: 2022/01/25 23:49:17 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	sig_handler(int act)
{
	static int	bit;
	static int	c;

	if (act == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	action;

	(void)argv;
	action.sa_handler = &sig_handler;
	if (argc == 1)
	{
		ft_printf("PID: %d\n", getpid());
		while (42)
		{
			sigaction(SIGUSR1, &action, NULL);
			sigaction(SIGUSR2, &action, NULL);
			pause();
		}
	}
	return (0);
}
