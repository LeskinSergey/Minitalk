/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbombadi <sbombadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:54:44 by sbombadi          #+#    #+#             */
/*   Updated: 2021/11/15 20:54:59 by sbombadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	int		f;
	int		len;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	f = 0;
	if (n < 0)
	{
		f = 1;
		n *= -1;
	}
	len = ft_nbrlen(n);
	s = malloc(sizeof(char) * len + f + 1);
	if (!s)
		return (NULL);
	s[len + f] = '\0';
	while (len > 0)
	{
		s[--len + f] = n % 10 + 48;
		n /= 10;
	}
	if (f)
		s[0] = '-';
	return (s);
}

int	ft_print_d(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa(n);
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
	return (i);
}
