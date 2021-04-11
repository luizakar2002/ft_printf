/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_hex_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:13:02 by lukarape          #+#    #+#             */
/*   Updated: 2021/03/31 18:45:38 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*int_to_hex_p(long long unsigned int number)
{
	char						*ch;
	char						*str;
	char						*ptr;
	int							l;

	ch = "0123456789abcdef";
	l = ft_hexlen_p(number);
	if (!(str = (char *)malloc(sizeof(char) * (l + 1))))
		return (0);
	ptr = str;
	while (l > 2)
	{
		*ptr = ch[number % 16];
		number /= 16;
		l--;
		ptr++;
	}
	*ptr = 'x';
	ptr++;
	*ptr = '0';
	ptr++;
	*ptr = '\0';
	str = ft_strrev(str);
	return (str);
}
