/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:27:26 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 16:45:29 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ch(int size, int number, t_flags flags, char *itoa)
{
	if (size >= ft_intlen(number) && flags.zero == 0)
	{
		if (flags.dotzero && flags.check == 0)
			itoa = itoa + 0;
		else
			itoa = " ";
	}
	else
		itoa = "\0";
	return (itoa);
}

char	*ft_merge_int(int size, int number, t_flags flags)
{
	char	*merge;
	char	*itoa;
	int		i;
	int		j;

	itoa = ft_itoa(number);
	if (flags.dot == 0 && number == 0)
	{
		itoa = ch(size, number, flags, itoa);
		if (size == ft_intlen(number) && flags.zero == 0 && flags.width == 0)
			size -= 1;
	}
	merge = malloc(sizeof(char) * (size + 1));
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
