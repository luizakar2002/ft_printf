/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 17:05:46 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 14:54:35 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*dot_str(char *ptr, t_flags flags)
{
	if (flags.dot)
		return (ptr);
	return (ptr);
}

char	*minus_str(char *str, int i)
{
	char	*ptr;
	char	*ptr2;
	char	temp;

	ptr = str;
	while (*ptr != '\0' && i-- > 0)
	{
		ptr++;
	}
	ptr2 = str;
	while (*ptr != '\0' && *ptr2 != '\0')
	{
		temp = *ptr2;
		*ptr2 = *ptr;
		*ptr = temp;
		ptr++;
		ptr2++;
	}
	return (str);
}

int		find_max_str(t_flags flags, int length)
{
	int max_width;
	int i;
	int arr[3];

	arr[0] = length;
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

char	*checks(t_flags flags, char *merge, int length, char *string)
{
	int i;

	i = (int)ft_strlen(merge) - length;
	if (flags.width > flags.dot && flags.dot != -1
			&& flags.dot < (int)ft_strlen(string))
		i = flags.width - flags.dot;
	if (flags.dot > 0)
		merge = dot_str(merge, flags);
	if (flags.width && flags.dot == -1)
		merge = star_str(merge, flags.width - (int)ft_strlen(string),
				(int)ft_strlen(string), flags);
	if (flags.width && flags.dot == 0)
		merge = star_str(merge, flags.width, 0, flags);
	if (flags.width && flags.dot > 0 && (merge[0] == ' ' ||
				merge[0] == '0') && string[0] != '0')
		merge = star_str(merge, flags.width - flags.dot,
				(int)ft_strlen(string), flags);
	if (flags.minus && (merge[0] == ' ' || merge[0] == '0') && string[0] != '0')
		merge = minus_str(merge, i);
	else if (flags.minus && merge[0] != '0' && string[0] == '0')
		merge = minus_str(merge, i);
	if (!flags.minus && merge[0] == '0' && string[0] == '0')
		merge = minus_str(merge, i);
	return (merge);
}

int		ft_handle_str(char *merge, t_flags flags, char *string)
{
	int			size;
	int			length;
	const char	*str;
	t_flags		flag;

	str = "(null)";
	flag = flags;
	if (flags.dot == 0)
		string = "\0";
	if (string == NULL)
		string = (char *)str;
	length = (int)ft_strlen(string);
	if (flags.dot < (int)ft_strlen(string) && flags.dot > 0)
		length = 0;
	else if (flags.dot > (int)ft_strlen(string) && flags.dot != 0)
		flags.dot = 0;
	size = find_max_str(flags, length);
	flags = flag;
	merge = ft_merge_str(size, string, flags);
	length = (int)ft_strlen(string);
	merge = checks(flags, merge, length, string);
	ft_putstr(merge);
	size = (int)ft_strlen(merge);
	return (size);
}
