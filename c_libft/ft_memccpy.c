/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 05:34:00 by student           #+#    #+#             */
/*   Updated: 2020/05/16 19:58:35 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*s_get;
	unsigned char	*s_take;
	size_t			step;

	s_get = (unsigned char *)dst;
	s_take = (unsigned char *)src;
	step = 0;
	if (!n)
		return (NULL);
	while (step < n)
	{
		s_get[step] = s_take[step];
		if (s_take[step] == (unsigned char)c)
			return (dst + step + 1);
		step++;
	}
	return (NULL);
}
