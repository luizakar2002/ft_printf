/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:05:10 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/03 20:08:16 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle(char c, t_flags flags, va_list args)
{
	int		r;
	char	*merge;

	merge = NULL;
	r = 0;
	if (c == 'd' || c == 'i')
		r += ft_handle_int(merge, flags, va_arg(args, int));
	else if (c == 's')
		r += ft_handle_str(merge, flags, va_arg(args, char *));
	else if (c == 'c')
		r += ft_handle_char(flags, va_arg(args, int));
	else if (c == 'u')
		r += ft_handle_u(merge, flags, va_arg(args, int));
	else if (c == 'x' || c == 'X')
		r += ft_handle_x(merge, flags, va_arg(args, int), c);
	else if (c == 'p')
		r += ft_handle_p(merge, flags, va_arg(args, long long unsigned int));
	else if (c == '%')
		r += ft_handle_percent(flags, '%');
	free(merge);
	return (r);
}
