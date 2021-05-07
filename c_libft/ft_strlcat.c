/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 21:34:28 by student           #+#    #+#             */
/*   Updated: 2020/05/16 19:55:59 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t step;

	step = 0;
	if (size)
	{
		while (dst[step])
			step++;
		if (step > size)
			step = size;
		while (step < size - 1 && *src)
			dst[step++] = *(src++);
		if (step != size)
			dst[step] = '\0';
	}
	while (*src)
	{
		src++;
		step++;
	}
	return (step);
}
