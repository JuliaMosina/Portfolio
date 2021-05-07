/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:44:18 by student           #+#    #+#             */
/*   Updated: 2020/06/12 05:16:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	flag_start(int *rez, t_printf_format *s_format, int *bef_dot,
		int sym)
{
	if (!s_format->pres_dot && sym == '0' && s_format->set_dot)
		(*rez)--;
	if (s_format->set_dot)
		s_format->zero = ' ';
	*bef_dot = 0;
	if (*rez < s_format->pres_dot)
		*bef_dot = s_format->pres_dot - *rez;
}

static void	flag_end(int *rez, t_printf_format s_format, int *bef_dot, int sym)
{
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez
				- *bef_dot);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
	if (s_format.pres_dot || sym != '0' || !s_format.set_dot)
		write(1, &sym, 1);
}

static int	ft_nbr(int n, int rez, char before_put, t_printf_format s_format)
{
	int		step;
	char	sym;
	int		bef_dot;

	step = n / 10;
	rez++;
	sym = '0' + n % 10;
	if (step > 0)
	{
		rez = ft_nbr(step, rez, before_put, s_format);
		write(1, &sym, 1);
	}
	else
	{
		flag_start(&rez, &s_format, &bef_dot, sym);
		if (before_put != '\0')
			rez++;
		if (s_format.zero == ' ')
			rez = rez + char_repeat(s_format.zero, s_format.num - rez
					- bef_dot);
		if (before_put != '\0')
			write(1, &before_put, 1);
		flag_end(&rez, s_format, &bef_dot, sym);
	}
	return (rez);
}

int			print_d(int n, t_printf_format s_format)
{
	char	sym;
	int		rez;

	rez = 0;
	if (n < 0)
	{
		if (n / 10)
		{
			rez = ft_nbr((n / 10) * -1, rez + 1, '-', s_format);
			sym = '0' + (n % 10) * -1;
			write(1, &sym, 1);
		}
		else
			rez = ft_nbr(n * -1, rez, '-', s_format);
	}
	else
	{
		if (!s_format.add_plus)
			s_format.add_plus = s_format.is_space;
		rez = ft_nbr(n, rez, s_format.add_plus, s_format);
	}
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
