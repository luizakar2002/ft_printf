/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:28:33 by lukarape          #+#    #+#             */
/*   Updated: 2021/03/30 18:29:34 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_merge_p(int size, long long unsigned int number, t_flags flags)
{
	char	*merge;
	char	*hex;
	int		i;
	int		j;

	hex = int_to_hex_p(number);
	if (flags.dot == 0 && number == 0)
	{
		hex = "\0";
		if (size == ft_intlen_u(number))
			size -= 1;
	}
	if (!(merge = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
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
