/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 07:05:43 by student           #+#    #+#             */
/*   Updated: 2020/06/15 01:33:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void		print_p_ch(unsigned long long n)
{
	char		sym;

	if (n < 10)
		sym = '0' + n;
	else
		sym = 'a' + (n - 10);
	write(1, &sym, 1);
}

static void		flag_loc(int *rez, t_printf_format s_format,
		unsigned long long *bef_dot, int sym)
{
	if (!s_format.pres_dot && sym == 0 && s_format.set_dot)
		(*rez)--;
	if (s_format.set_dot)
		s_format.zero = ' ';
	*bef_dot = 0;
	if (*rez < s_format.pres_dot)
		*bef_dot = s_format.pres_dot - *rez;
	(*rez) += 2;
	if (s_format.zero == ' ')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez
				- *bef_dot);
	write(1, "0x", 2);
	if (s_format.zero == '0')
		*rez = *rez + char_repeat(s_format.zero, s_format.num - *rez
				- *bef_dot);
	if (*bef_dot)
		*rez = *rez + char_repeat('0', *bef_dot);
	if (s_format.pres_dot || sym != 0 || !s_format.set_dot)
		print_p_ch(sym);
}

static int		nbr_p(unsigned long long n, int rez, t_printf_format s_format)
{
	unsigned long long	step;
	unsigned long long	bef_dot;
	int					sym;

	step = n / 16;
	rez++;
	sym = n % 16;
	if (step > 0)
	{
		rez = nbr_p(step, rez, s_format);
		print_p_ch(sym);
	}
	else
		flag_loc(&rez, s_format, &bef_dot, sym);
	return (rez);
}

int				print_p(unsigned long long n, t_printf_format s_format)
{
	int			rez;

	rez = nbr_p(n, 0, s_format);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez);
	return (rez);
}
