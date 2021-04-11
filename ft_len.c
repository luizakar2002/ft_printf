/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:20:59 by lukarape          #+#    #+#             */
/*   Updated: 2021/03/30 18:25:27 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	const char		*s;
	int				i;

	s = str;
	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

int		ft_intlen(int n)
{
	int			i;
	long long	t;

	i = 1;
	t = n;
	if (t < 0)
	{
		t = t * -1;
		i++;
	}
	while (t >= 10)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

int		ft_intlen_u(unsigned int n)
{
	int			i;
	long long	t;

	i = 1;
	t = n;
	if (t < 0)
	{
		t = t * -1;
		i++;
	}
	while (t >= 10)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

int		ft_hexlen(unsigned int number)
{
	int				l;
	unsigned int	n;

	n = number;
	l = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		l++;
	}
	return (l);
}

int		ft_hexlen_p(long long unsigned int number)
{
	int						l;
	long long unsigned int	n;

	n = number;
	l = 0;
	if (n == 0)
		return (3);
	while (n > 0)
	{
		n /= 16;
		l++;
	}
	l += 2;
	return (l);
}
