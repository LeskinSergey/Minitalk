/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:48:49 by sbombadi          #+#    #+#             */
/*   Updated: 2022/01/26 20:36:10 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

void	handler(int act, siginfo_t *t, void *tmp);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
void	send(unsigned char c, int pid);
void	do_kill(int pid, int *mass);
#endif
