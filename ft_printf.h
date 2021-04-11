/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:28:07 by lukarape          #+#    #+#             */
/*   Updated: 2021/04/11 14:50:59 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_flags
{
	int	minus;
	int	dot;
	int	star;
	int	zero;
	int	width;
	int	type;
	int	dotzero;
	int check;
}				t_flags;

int				is_specifier(char c);
t_flags			*ft_handle_minus(t_flags *flags);
int				ft_handle_dot(t_flags *flags, va_list args, const char *keep,
				int i);
t_flags			*ft_handle_star(t_flags *flags, va_list args);
t_flags			*ft_handle_digit(t_flags *flags, char c);
t_flags			*ft_handle_zero(t_flags *flags, int i, const char *keep);
char			*star_d(char *str, int count, int number, t_flags flags);
char			*dot_d(char *str, int count, int i, t_flags flags);
char			*minus_d(char *str);
char			*star_u(char *ptr, int count, unsigned int number,
				t_flags flags);
char			*star_str(char *ptr, int count, int i, t_flags flags);
char			*star_x(char *ptr, int count, unsigned int number,
				t_flags flags);
char			*dot_u(char *ptr, int count, int i, t_flags flags);
char			*dot_x(char *ptr, int count, int i, t_flags flags);
char			*minus_u(char *str);
char			*minus_x(char *str);
int				find_max(t_flags flags, int number);
int				find_max_str(t_flags flags, int length);
int				find_max_c(t_flags flags);
int				find_max_u(t_flags flags, unsigned int number);
int				ft_handle_int(char *merge, t_flags flags, int number);
int				ft_handle_str(char *merge, t_flags flags, char *string);
int				ft_handle_char(t_flags flags, char ch);
int				ft_handle_percent(t_flags flags, char c);
int				ft_handle_u(char *merge, t_flags flags, unsigned int number);
int				ft_handle_x(char *merge, t_flags flags, unsigned int number,
				char c);
int				ft_handle_p(char *merge, t_flags flags,
				long long unsigned int number);
int				ft_handle(char c, t_flags flags, va_list args);
char			*ft_merge_int(int size, int number, t_flags flags);
char			*ft_merge_str(int size, char *string, t_flags flags);
char			*ft_merge_char(int size, char ch);
char			*ft_merge_u(int size, unsigned int number, t_flags flags);
char			*ft_merge_x(int size, unsigned int number, t_flags flags);
char			*ft_merge_p(int size, long long unsigned int number,
				t_flags flags);
int				ft_putchar(char c);
int				ft_printf(const char *format, ...);
int				ft_intlen(int n);
int				ft_intlen_u(unsigned int n);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
char			*ft_strdup(const char *str);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
int				is_flag(char c);
void			*ft_memset(void *str, int c, size_t n);
void			ft_putstr(char *str);
char			*ft_strrev(char *str);
char			*int_to_hex(unsigned int number);
char			*int_to_hex_p(long long unsigned int n);
int				ft_hexlen(unsigned int number);
int				ft_hexlen_p(long long unsigned int number);
int				ft_isalnum(int c);
char			*che(int size, unsigned int number, t_flags flags, char *hex);

#endif
