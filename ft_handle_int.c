/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:48:09 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 16:44:58 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*minus_d(char *str)
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

int		find_max(t_flags flags, int number)
{
	int max_width;
	int i;
	int arr[3];

	arr[0] = ft_intlen(number);
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

int		negative_number(int *number, int *size, t_flags flags)
{
	if (*number < 0)
	{
		if (flags.width <= flags.dot && flags.dot >= ft_intlen(*number)
				&& !flags.zero && flags.check)
			*size += 1;
		*number *= -1;
		return (1);
	}
	return (0);
}

char	*act_negative_number(char *merge, t_flags flags, int l)
{
	int i;

	i = 0;
	if (flags.width <= l && flags.dot <= l)
		merge[0] = '-';
	if (flags.width >= flags.dot && !ft_isdigit(merge[0]))
	{
		while (merge[i])
		{
			if (ft_isdigit(merge[i]))
			{
				merge[i - 1] = '-';
				break ;
			}
			i++;
		}
	}
	else if (flags.width <= flags.dot)
		merge[0] = '-';
	return (merge);
}

int		ft_handle_int(char *merge, t_flags flags, int number)
{
	int size;
	int i;
	int flag;

	size = find_max(flags, number);
	flag = negative_number(&number, &size, flags);
	merge = ft_merge_int(size, number, flags);
	i = ft_strlen(merge) - ft_intlen(number);
	if (flags.dot > 0 && flags.width > flags.dot)
		merge = dot_d(merge, flags.dot - ft_intlen(number),
				flags.width - flags.dot - 1, flags);
	if (flags.width && flags.dot < 0)
		merge = star_d(merge, flags.width - ft_intlen(number), number, flags);
	if (flags.width && flags.dot == 0)
		merge = star_d(merge, flags.width - ft_intlen(number), number, flags);
	if (flags.width && flags.dot > 0 && flags.width > flags.dot)
		merge = star_d(merge, flags.width - flags.dot, number, flags);
	if (flag)
		merge = act_negative_number(merge, flags, ft_intlen(number));
	if (flags.minus)
		merge = minus_d(merge);
	ft_putstr(merge);
	i = ft_strlen(merge);
	return (i);
}
