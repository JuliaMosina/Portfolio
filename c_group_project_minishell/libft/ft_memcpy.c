/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 04:14:57 by student           #+#    #+#             */
/*   Updated: 2020/05/16 19:57:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*s_get;
	unsigned char	*s_take;
	size_t			step;

	if (!n || (!src && !dst))
		return (dst);
	s_get = (unsigned char *)dst;
	s_take = (unsigned char *)src;
	step = 0;
	while (step < n)
	{
		s_get[step] = s_take[step];
		step++;
	}
	return (s_get);
}
