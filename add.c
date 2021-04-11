/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:55:33 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 14:51:14 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*star_d(char *ptr, int count, int number, t_flags flags)
{
	int i;

	i = 0;
	if (number == 0 && flags.width && flags.dot == 0)
		count++;
	if (flags.width > flags.dot && flags.dot < ft_intlen(number))
		count = flags.width - ft_intlen(number);
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

char	*dot_d(char *ptr, int count, int i, t_flags flags)
{
	if (!flags.dot)
		return (ptr);
	while (i < count)
	{
		ptr[i] = '0';
		i++;
	}
	return (ptr);
}

int		is_specifier(char c)
{
	return (c == 'i' || c == 'd' || c == 'c' || c == 's'
			|| c == 'p' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}

int		is_flag(char c)
{
	return (c == '.' || c == '0' || c == '*' || c == '-');
}

char	*star_str(char *ptr, int count, int i, t_flags flags)
{
	if (count < 0)
	{
		if (flags.width < flags.dot)
			count = 0;
		else
			count = flags.width;
		if (flags.width < i && i != 0)
			count = 0;
	}
	i = 0;
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}
