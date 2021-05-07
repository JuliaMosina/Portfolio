/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 07:09:05 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:06:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ful_fill(char *rez, size_t len, int n, int step)
{
	step = n;
	if (!n)
		rez[0] = '0';
	else if (n < 0)
	{
		rez[0] = '-';
		len--;
		rez[len] = '0' + (step % 10) * -1;
		step = step / 10 * -1;
	}
	while (step)
	{
		len--;
		rez[len] = '0' + step % 10;
		step = step / 10;
	}
	return (rez);
}

char		*ft_itoa(int n)
{
	char	*rez;
	size_t	len;
	int		step;

	step = n;
	if (!n)
		len = 1;
	else if (n < 0)
		len = 1;
	else
		len = 0;
	while (step)
	{
		step = step / 10;
		len++;
	}
	rez = (char *)malloc(sizeof(char) * (len + 1));
	if (!rez)
		return (NULL);
	rez[len] = '\0';
	rez = ful_fill(rez, len, n, step);
	return (rez);
}
