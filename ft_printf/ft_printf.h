/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:55:45 by sbombadi          #+#    #+#             */
/*   Updated: 2021/11/15 20:55:48 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include<stddef.h>

int	ft_printf(const char *arg, ...);
int	ft_print_c(int c);
int	ft_print_str(char *str);
int	ft_print_d(int n);
int	ft_print_p(void *ptr, char c);
int	ft_print_u( unsigned int n);
int	ft_print_x(unsigned int ptr, char c);

#endif
