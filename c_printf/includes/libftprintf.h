/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:12:57 by student           #+#    #+#             */
/*   Updated: 2020/06/15 02:11:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>

typedef struct	s_struct
{
	int		num;
	char	zero;
	char	add_plus;
	int		pres_dot;
	int		set_dot;
	char	is_space;
	char	is_octo;
}				t_printf_format;
int				print_s(const char *str, t_printf_format s_format);
int				ft_strlen(const char *s);
int				print_c(char c, t_printf_format s_format);
int				print_d(int n, t_printf_format s_format);
int				ft_printf(const char *format, ...);
int				print_u(unsigned int n, t_printf_format s_format);
int				print_x(unsigned int n, t_printf_format s_format);
int				print_bigx(unsigned int n, t_printf_format s_format);
int				print_p(unsigned long long n, t_printf_format s_format);
int				format_analyze(const char **str, t_printf_format *s_format,
				char *format_let, va_list param);
int				char_repeat(char c, int num);
int				in_array(char c, const char *arr);
void			set_default(char *format_let, int *neg,
		t_printf_format *s_format);

#endif
