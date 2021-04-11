/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:08:28 by lukarape          #+#    #+#             */
/*   Updated: 2021/03/30 18:10:28 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*star_u(char *ptr, int count, unsigned int number, t_flags flags)
{
	int i;

	i = 0;
	if (number == 0 && flags.width && flags.dot == 0)
		count++;
	if (flags.width > flags.dot && flags.dot < ft_intlen_u(number))
	{
		count = flags.width - ft_intlen_u(number);
	}
	while (i < count)
	{
		ptr[i] = ' ';
		i++;
	}
	return (ptr);
}

char	*dot_u(char *ptr, int count, int i, t_flags flags)
{
	if (!flags.dot)
		return (ptr);
	while (i < count)
	{
		ptr[i] = '0';
		i++;
	}
	return (ptr);
}

char	*minus_u(char *str)
{
	char	*ptr;
	char	*ptr2;
	char	temp;

	ptr = str;
	while (*ptr)
	{
		if (ft_isdigit(*ptr) || *ptr == '-')
			break ;
		ptr++;
	}
	ptr2 = str;
	while (*ptr && *ptr2)
	{
		temp = *ptr2;
		*ptr2 = *ptr;
		*ptr = temp;
		ptr++;
		ptr2++;
	}
	return (str);
}

int		find_max_u(t_flags flags, unsigned int number)
{
	int max_width;
	int i;
	int arr[3];

	arr[0] = ft_intlen_u(number);
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

int		ft_handle_u(char *merge, t_flags flags, unsigned int number)
{
	int size;
	int i;

	size = find_max_u(flags, number);
	merge = ft_merge_u(size, number, flags);
	i = ft_strlen(merge) - ft_intlen_u(number);
	if (flags.dot > 0 && flags.width > flags.dot)
		merge = dot_u(merge, flags.dot - ft_intlen_u(number),
				flags.width - flags.dot - 1, flags);
	if (flags.width && flags.dot < 0)
		merge = star_u(merge, flags.width - ft_intlen_u(number), number, flags);
	if (flags.width && flags.dot == 0)
		merge = star_u(merge, flags.width - ft_intlen_u(number), number, flags);
	if (flags.width && flags.dot > 0 && flags.width > flags.dot)
		merge = star_u(merge, flags.width - flags.dot, number, flags);
	if (flags.minus)
		merge = minus_u(merge);
	ft_putstr(merge);
	i = ft_strlen(merge);
	return (i);
}
