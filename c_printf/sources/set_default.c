/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 00:47:03 by student           #+#    #+#             */
/*   Updated: 2020/06/12 00:51:56 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	set_default(char *format_let, int *neg,
		t_printf_format *s_format)
{
	s_format->zero = ' ';
	s_format->add_plus = '\0';
	s_format->num = 0;
	s_format->set_dot = 0;
	s_format->pres_dot = 0;
	s_format->is_space = '\0';
	s_format->is_octo = '\0';
	*neg = 1;
	*format_let = '\0';
}
