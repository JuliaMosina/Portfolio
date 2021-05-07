/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 09:12:06 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:07:28 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			step;
	unsigned char	*str;

	step = 0;
	str = (unsigned char *)s;
	while (step < n)
	{
		if (str[step] == (unsigned char)c)
			return (str + step);
		step++;
	}
	return (NULL);
}
