/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:15:20 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:40:57 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned	int		selection(const char *str)
{
	unsigned int		safe;

	safe = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			safe = safe * 10 + (*str - '0');
		else
			return (safe);
		str++;
	}
	return (safe);
}

int						ft_atoi(const char *str)
{
	int					safe;
	int					negative;

	safe = 0;
	negative = 1;
	while (*str == ' ' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	safe = selection(str);
	return (safe * negative);
}
