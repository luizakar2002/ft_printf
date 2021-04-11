/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 19:39:24 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/28 19:58:59 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int				idx;
	int				is_negative;
	unsigned int	positive_n;
	char			*value;

	if (n == 0)
		return (ft_strdup("0"));
	if (!(value = (char *)malloc(sizeof(char) * (ft_intlen(n) + 1))))
		return (NULL);
	ft_memset(value, '\0', (ft_intlen(n) + 1));
	is_negative = n < 0 ? 1 : 0;
	positive_n = n < 0 ? -n : n;
	idx = 0;
	while (positive_n != 0)
	{
		value[idx++] = (positive_n % 10) + '0';
		positive_n = positive_n / 10;
	}
	if (is_negative)
		value[idx++] = '-';
	return (ft_strrev(value));
}
