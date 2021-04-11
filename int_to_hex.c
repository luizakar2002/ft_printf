/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:09:40 by lukarape          #+#    #+#             */
/*   Updated: 2021/03/31 18:48:17 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_hex(unsigned int n)
{
	char			*ch;
	char			*str;
	char			*ptr;
	unsigned int	number;
	int				l;

	ch = "0123456789abcdef";
	number = n;
	l = ft_hexlen(number);
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	ptr = str;
	while (l > 0)
	{
		*ptr = ch[number % 16];
		number /= 16;
		l--;
		ptr++;
	}
	*ptr = '\0';
	str = ft_strrev(str);
	return (str);
}
