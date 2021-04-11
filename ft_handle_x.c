/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:11:13 by lukarape          #+#    #+#             */
/*   Updated: 2021/03/30 18:14:44 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dot_x(char *ptr, int count, int i, t_flags flags)
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

char	*minus_x(char *str)
{
	char	*ptr;
	char	*ptr2;
	char	temp;

	ptr = str;
	while (*ptr)
	{
		if (ft_isdigit(*ptr) || ft_isalnum(*ptr))
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

int		find_max_x(t_flags flags, unsigned int number)
{
	int max_width;
	int i;
	int arr[3];

	arr[0] = ft_hexlen(number);
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

char	*ft_toupper(char *c)
{
	char *str;

	str = c;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
	return (c);
}

int		ft_handle_x(char *merge, t_flags flags, unsigned int number, char c)
{
	int size;
	int i;

	size = find_max_x(flags, number);
	merge = ft_merge_x(size, number, flags);
	i = ft_strlen(merge) - ft_hexlen(number);
	if (flags.dot > 0 && flags.width > flags.dot)
		merge = dot_x(merge, flags.dot - ft_hexlen(number),
				flags.width - flags.dot - 1, flags);
	if (flags.width && flags.dot < 0)
		merge = star_x(merge, flags.width - ft_hexlen(number), number, flags);
	if (flags.width && flags.dot == 0)
		merge = star_x(merge, flags.width - ft_hexlen(number), number, flags);
	if (flags.width && flags.dot > 0 && flags.width > flags.dot)
		merge = star_x(merge, flags.width - flags.dot, number, flags);
	if (flags.minus)
		merge = minus_x(merge);
	if (c == 'X')
		merge = ft_toupper(merge);
	ft_putstr(merge);
	i = ft_strlen(merge);
	return (i);
}
