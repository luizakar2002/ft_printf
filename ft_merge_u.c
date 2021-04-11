/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:41:11 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/03 20:18:54 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_merge_u(int size, unsigned int number, t_flags flags)
{
	char	*merge;
	char	*itoa;
	int		i;
	int		j;

	itoa = ft_itoa_u(number);
	if (flags.dot == 0 && number == 0)
	{
		itoa = che(size, number, flags, itoa);
		if (size == ft_intlen_u(number) && flags.zero == 0 && flags.width == 0)
			size -= 1;
	}
	merge = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
		merge[i++] = '0';
	merge[i] = '\0';
	i = size - ft_strlen(itoa);
	j = 0;
	while (i < size)
		merge[i++] = itoa[j++];
	return (merge);
}
