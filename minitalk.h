/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 23:46:04 by sbombadi          #+#    #+#             */
/*   Updated: 2022/01/25 23:48:27 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include "ft_printf/ft_printf.h"

void	sig_handler(int act);
void	ft_putchar_fd(char c, int fd);
int		ft_atoi(const char *str);
void	send(unsigned char c, int pid);
#endif
