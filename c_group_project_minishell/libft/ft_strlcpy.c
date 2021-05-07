/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 01:08:27 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:47:11 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	rez;
	size_t	step;

	if (!dst || !src)
		return (0);
	rez = 0;
	while (src[rez])
		rez++;
	step = rez;
	if (!size)
		return (rez);
	if (step > size - 1)
		step = size - 1;
	dst[step] = '\0';
	if (step > 0)
	{
		while (step > 0)
		{
			step--;
			dst[step] = src[step];
		}
	}
	return (rez);
}
