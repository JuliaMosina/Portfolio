/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_repeat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 22:35:13 by student           #+#    #+#             */
/*   Updated: 2020/06/11 06:18:34 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		char_repeat(char c, int num)
{
	int	step;

	step = 0;
	while (step < num)
	{
		write(1, &c, 1);
		step++;
	}
	return (step);
}
