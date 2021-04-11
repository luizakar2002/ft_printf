/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:43:25 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 15:22:10 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.type = 0;
	flags.dotzero = 0;
	flags.check = 1;
	return (flags);
}

int		ft_flag_parse(const char *keep, int i, t_flags *flags, va_list args)
{
	while (keep[i])
	{
		if (is_specifier(keep[i]))
			break ;
		else if (keep[i] == '-')
			flags = ft_handle_minus(flags);
		else if (keep[i] == '.' || flags->zero == 1)
			i = ft_handle_dot(flags, args, keep, i);
		else if (keep[i] == '*')
			flags = ft_handle_star(flags, args);
		else if (keep[i] == '0' && !(ft_isdigit(keep[i - 1])))
			flags = ft_handle_zero(flags, i, keep);
		else if (ft_isdigit(keep[i]))
			flags = ft_handle_digit(flags, keep[i]);
		i++;
	}
	return (i);
}

int		ft_handle_keep(const char *keep, va_list args)
{
	int		char_count;
	int		i;
	t_flags	flags;

	char_count = 0;
	i = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!keep[i])
			break ;
		else if (keep[i] == '%' && keep[i + 1])
		{
			i = ft_flag_parse(keep, ++i, &flags, args);
			if (is_specifier(keep[i]))
				char_count += ft_handle(keep[i], flags, args);
			else if (keep[i])
				char_count += ft_putchar(keep[i]);
		}
		else if (keep[i] != '%')
			char_count += ft_putchar(keep[i]);
		i++;
	}
	return (char_count);
}

int		ft_printf(const char *format, ...)
{
	const char	*keep;
	va_list		args;
	int			char_count;

	char_count = 0;
	keep = ft_strdup(format);
	va_start(args, format);
	char_count += ft_handle_keep(keep, args);
	free((char *)keep);
	va_end(args);
	return (char_count);
}
