/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:42:11 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 16:45:50 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*che(int size, unsigned int number, t_flags flags, char *hex)
{
	if (size >= ft_intlen(number) && flags.zero == 0)
	{
		if (flags.dotzero && flags.check == 0)
			hex = hex + 0;
		else
			hex = " ";
	}
	else
		hex = "\0";
	return (hex);
}

char	*ft_merge_x(int size, unsigned int number, t_flags flags)
{
	char	*merge;
	char	*hex;
	int		i;
	int		j;

	hex = int_to_hex(number);
	if (flags.dot == 0 && number == 0)
	{
		hex = che(size, number, flags, hex);
		if (size == ft_intlen_u(number) && flags.zero == 0 && flags.width == 0)
			size -= 1;
	}
	merge = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
		merge[i++] = '0';
	merge[i] = '\0';
	i = size - ft_strlen(hex);
	j = 0;
	while (i < size)
		merge[i++] = hex[j++];
	return (merge);
}
