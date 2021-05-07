/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 23:58:13 by student           #+#    #+#             */
/*   Updated: 2020/06/11 07:13:58 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_s(const char *str, t_printf_format s_format)
{
	int	rez;
	int	sym_add;

	if (!str)
		str = "(null)";
	rez = ft_strlen(str);
	if (s_format.set_dot && rez > s_format.pres_dot)
		rez = s_format.pres_dot;
	sym_add = char_repeat(s_format.zero, s_format.num - rez);
	if (rez)
		write(1, str, rez);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez - sym_add);
	return (rez + sym_add);
}
