/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 18:29:41 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/03 20:17:37 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_merge(t_flags flags, char *string, int i, int size)
{
	if (flags.dot == -1)
		i = size - (int)ft_strlen(string);
	else if (flags.dot < 0)
		i = size - flags.dot;
	else if (flags.width >= flags.dot && flags.dot != -1 &&
			flags.dot >= (int)ft_strlen(string))
		i = size - (int)ft_strlen(string);
	else if (flags.width >= flags.dot && flags.dot != -1 &&
			flags.dot < (int)ft_strlen(string))
		i = flags.width - flags.dot;
	else if (flags.width < flags.dot && flags.dot != -1)
		i = size - (int)ft_strlen(string);
	else
		i = 0;
	return (i);
}

char	*ft_merge_str(int size, char *string, t_flags flags)
{
	char	*merge;
	int		i;
	int		j;

	merge = malloc(sizeof(char) * (size + 1));
	i = 0;
	while (i < size)
		merge[i++] = ' ';
	merge[i] = '\0';
	i = check_merge(flags, string, i, size);
	j = 0;
	if (i < 0)
		i = 0;
	while (i < size && j < (int)ft_strlen(string))
		merge[i++] = string[j++];
	return (merge);
}
