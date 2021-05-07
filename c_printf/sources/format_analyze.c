/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_analyze.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:24:28 by student           #+#    #+#             */
/*   Updated: 2020/06/12 22:31:42 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		flag_dot(t_printf_format *s_format, const char **str_loc,
		va_list param)
{
	s_format->set_dot = 1;
	(*str_loc)++;
	if ((**str_loc >= '0' && **str_loc <= '9') || **str_loc == '*')
	{
		if (**str_loc == '*')
		{
			s_format->pres_dot = va_arg(param, int);
			if (s_format->pres_dot < 0)
			{
				s_format->set_dot = 0;
				s_format->pres_dot = 0;
			}
		}
		else
		{
			s_format->pres_dot = 0;
			while (**str_loc >= '0' && **str_loc <= '9')
				s_format->pres_dot = s_format->pres_dot * 10 +
					(*((*str_loc)++) - '0');
			(*str_loc)--;
		}
	}
	else
		(*str_loc)--;
}

static void		flag_star(const char **str_loc, va_list param,
		t_printf_format *s_format, int *neg)
{
	if (**str_loc == '*')
	{
		s_format->num = va_arg(param, int);
		if (s_format->num < 0)
		{
			s_format->num *= -1;
			*neg = -1;
		}
	}
	else
	{
		s_format->num = 0;
		while (**str_loc >= '0' && **str_loc <= '9')
		{
			s_format->num = s_format->num * 10 + (**str_loc - '0');
			(*str_loc)++;
		}
		(*str_loc)--;
	}
}

static int		flag_add(const char **str, char *format_let,
		const char **str_loc)
{
	if (in_array(**str_loc, "scdiuxXp%"))
		*format_let = **str_loc;
	else
	{
		(*str_loc)--;
		*format_let = '\0';
	}
	*str = *str_loc;
	return (1);
}

static void		flag_add_more(const char *str_loc, t_printf_format *s_format,
		int *neg)
{
	if (*str_loc == '0')
		s_format->zero = '0';
	else if (*str_loc == '+')
		s_format->add_plus = '+';
	else if (*str_loc == '-')
		*neg = -1;
	else if (*str_loc == ' ')
		s_format->is_space = ' ';
	else if (*str_loc == '#')
		s_format->is_octo = '#';
}

int				format_analyze(const char **str, t_printf_format *s_format,
		char *format_let, va_list param)
{
	const char	*str_loc;
	int			neg;

	str_loc = *str;
	set_default(format_let, &neg, s_format);
	if (!str_loc)
		return (0);
	while (str_loc)
	{
		if ((*str_loc >= '1' && *str_loc <= '9') || *str_loc == '*')
			flag_star(&str_loc, param, s_format, &neg);
		else if (*str_loc == '.')
			flag_dot(s_format, &str_loc, param);
		else if (in_array(*str_loc, "0+- #"))
			flag_add_more(str_loc, s_format, &neg);
		else if (!in_array(*str_loc, "_ ',:;"))
		{
			s_format->num *= neg;
			return (flag_add(str, format_let, &str_loc));
		}
		if (*str_loc)
			str_loc++;
	}
	*str = str_loc;
	return (1);
}
