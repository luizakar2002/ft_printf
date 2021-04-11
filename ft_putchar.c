/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:07:37 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/03 20:19:39 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putstr(char *str)
{
	char *ptr;

	ptr = str;
	while (*ptr != '\0')
	{
		write(1, ptr, 1);
		ptr++;
	}
}

int		ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9')
			|| (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (1);
	}
	return (0);
}

char	*star_x(char *ptr, int count, unsigned int number, t_flags flags)
{
	int i;

	i = 0;
	if (number == 0 && flags.width && flags.dot == 0)
		count++;
	if (flags.width > flags.dot && flags.dot < ft_hexlen(number))
		count = flags.width - ft_hexlen(number);
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}
