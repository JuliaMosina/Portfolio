/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 21:44:49 by student           #+#    #+#             */
/*   Updated: 2020/06/15 01:36:46 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			format_letter(char format_let, t_printf_format s_format,
		va_list param)
{
	if (format_let == '%')
		return (print_c('%', s_format));
	else if (format_let == 's')
		return (print_s(va_arg(param, char*), s_format));
	else if (format_let == 'd' || format_let == 'i')
		return (print_d(va_arg(param, int), s_format));
	else if (format_let == 'c')
		return (print_c(va_arg(param, int), s_format));
	else if (format_let == 'u')
		return (print_u(va_arg(param, unsigned int), s_format));
	else if (format_let == 'x')
		return (print_x(va_arg(param, unsigned int), s_format));
	else if (format_let == 'X')
		return (print_bigx(va_arg(param, unsigned int), s_format));
	else if (format_let == 'p')
		return (print_p((unsigned long long)va_arg(param, void *), s_format));
	else
		return (char_repeat(s_format.zero, s_format.num - 1));
}

int					ft_printf(const char *format, ...)
{
	int				rez;
	va_list			param;
	char			format_let;
	t_printf_format	s_format;

	format_let = '\0';
	va_start(param, format);
	rez = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!format_analyze(&format, &s_format, &format_let, param))
				return (0);
			rez += format_letter(format_let, s_format, param);
		}
		else
			rez += write(1, format, 1);
		if (*format)
			format++;
	}
	return (rez);
}
