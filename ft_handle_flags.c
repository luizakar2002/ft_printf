/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:42:13 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 15:22:14 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_star(t_flags *flags, va_list args)
{
	flags->star = 1;
	flags->dot = va_arg(args, int);
	flags->check = 1;
	if (flags->dotzero == 1 && flags->dot < 0 && flags->type == 0)
	{
		flags->dot = flags->width;
		flags->width = -1;
		flags->check = 0;
	}
	if (flags->dotzero == 1 && flags->dot < 0 && flags->type == 1)
	{
		flags->dot = -1;
		flags->check = 0;
	}
	if (flags->dot < 0 && flags->dot != -1)
	{
		if ((flags->zero == 1 || flags->dotzero == 1))
		{
			flags->minus = 1;
			flags->width = flags->dot * -1;
		}
		flags->dot = -1;
		flags->check = 0;
	}
	return (flags);
}

int		ft_handle_dot(t_flags *flags, va_list args, const char *keep, int i)
{
	if (keep[i] == '.')
		i++;
	if (keep[i] == '*')
		flags = ft_star(flags, args);
	else if (ft_isdigit(keep[i]))
	{
		flags->dot = 0;
		while (ft_isdigit(keep[i]) && keep[i] != '\0')
			flags->dot = (flags->dot * 10) + (keep[i++] - '0');
		i--;
	}
	else
	{
		flags->dot = 0;
		i--;
	}
	return (i);
}

t_flags	*ft_handle_star(t_flags *flags, va_list args)
{
	if (flags->star == 1 || flags->width)
		return (flags);
	flags->width = va_arg(args, int);
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->minus = 1;
		flags->type = 1;
	}
	return (flags);
}

t_flags	*ft_handle_digit(t_flags *flags, char c)
{
	flags->width *= 10;
	flags->width += c - '0';
	return (flags);
}

t_flags	*ft_handle_zero(t_flags *flags, int i, const char *keep)
{
	flags->zero = 1;
	while (keep[i])
	{
		if (keep[i] == '.')
		{
			flags->zero = 0;
			flags->dotzero = 1;
			break ;
		}
		i++;
	}
	return (flags);
}
