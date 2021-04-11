/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:10:53 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/03 20:08:48 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_width(int width, int minus, int has_zero)
{
	int char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		char_count++;
	}
	return (char_count);
}

int		ft_handle_char(t_flags flags, char c)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	char_count = ft_treat_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (char_count + 1);
}

int		ft_handle_percent(t_flags flags, char c)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
	{
		char_count += ft_putchar(c);
		if (flags.zero && flags.dot)
		{
			flags.zero = 0;
			flags.width = flags.dot;
			flags.dot = 0;
		}
	}
	if (flags.zero && flags.dot != -1)
		char_count += ft_treat_width(flags.dot, 1, flags.zero);
	else
		char_count += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putchar(c);
	return (char_count);
}
