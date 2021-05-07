/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 01:05:42 by student           #+#    #+#             */
/*   Updated: 2020/06/12 05:55:48 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	flag_loc(int *rez, t_printf_format s_format, int *bef_dot, int sym)
{
	if (!s_format.pres_dot && sym == '0' && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*bef_dot = 0;
	if (*rez < s_format.pres_dot)
		*bef_dot = s_format.pres_dot - *rez;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez
				- *bef_dot);
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez
				- *bef_dot);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
	if (s_format.pres_dot || sym != '0' || !s_format.set_dot)
		write(1, &sym, 1);
}

static int	ft_nbr(unsigned int n, int rez, t_printf_format s_format)
{
	int		step;
	char	sym;
	int		bef_dot;

	step = n / 10;
	rez++;
	sym = '0' + n % 10;
	if (step > 0)
	{
		rez = ft_nbr(step, rez, s_format);
		write(1, &sym, 1);
	}
	else
		flag_loc(&rez, s_format, &bef_dot, sym);
	return (rez);
}

int			print_u(unsigned int n, t_printf_format s_format)
{
	int		rez;

	rez = 0;
	rez = ft_nbr(n, rez, s_format);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
