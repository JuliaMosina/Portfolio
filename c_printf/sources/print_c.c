/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 00:54:54 by student           #+#    #+#             */
/*   Updated: 2020/06/11 06:56:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		print_c(char c, t_printf_format s_format)
{
	int	rez;
	int	sym_add;

	rez = 1;
	sym_add = char_repeat(s_format.zero, s_format.num - rez);
	write(1, &c, rez);
	rez = rez + char_repeat(' ', (s_format.num * -1) - rez - sym_add);
	return (rez + sym_add);
}
