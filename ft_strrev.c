/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:08:19 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/03 20:21:04 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	t;
	char	*ptr1;
	char	*ptr2;

	i = 0;
	size = ft_strlen(str);
	ptr1 = str;
	ptr2 = str;
	while (*ptr2)
		ptr2++;
	ptr2--;
	while (i < size / 2 && *ptr1 && *ptr2)
	{
		t = *ptr1;
		*ptr1 = *ptr2;
		*ptr2 = t;
		ptr1++;
		ptr2--;
		i++;
	}
	return (str);
}

t_flags	*ft_handle_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
	return (flags);
}
