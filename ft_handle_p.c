/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:03:29 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/06 19:11:03 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*star_p(char *ptr, int count, long long unsigned int number,
		t_flags flags)
{
	int i;

	i = 0;
	if (number == 0 && flags.width && flags.dot == 0)
		count++;
	if (flags.width > flags.dot && flags.dot < ft_hexlen_p(number))
		count = flags.width - ft_hexlen_p(number);
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

int		find_max_p(t_flags flags, long long unsigned int number)
{
	int max_width;
	int i;
	int arr[3];

	arr[0] = ft_hexlen_p(number);
	arr[1] = flags.dot;
	arr[2] = flags.width;
	i = 0;
	max_width = arr[0];
	while (i < 3)
	{
		if (arr[i] > max_width)
			max_width = arr[i];
		i++;
	}
	return (max_width);
}

int		ft_handle_p(char *merge, t_flags flags, long long unsigned int number)
{
	int size;
	int i;

	size = find_max_p(flags, number);
	merge = ft_merge_p(size, number, flags);
	i = ft_strlen(merge) - ft_hexlen_p(number);
	if (flags.dot > 0 && flags.width > flags.dot)
		merge = dot_x(merge, flags.dot - ft_hexlen_p(number),
				flags.width - flags.dot - 1, flags);
	if (flags.width && flags.dot < 0)
		merge = star_p(merge, flags.width - ft_hexlen_p(number), number, flags);
	if (flags.width && flags.dot == 0)
		merge = star_p(merge, flags.width - ft_hexlen_p(number), number, flags);
	if (flags.width && flags.dot > 0 && flags.width > flags.dot)
		merge = star_p(merge, flags.width - flags.dot, number, flags);
	if (flags.minus)
		merge = minus_x(merge);
	ft_putstr(merge);
	i = ft_strlen(merge);
	return (i);
}
