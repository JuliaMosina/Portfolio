/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 07:14:58 by student           #+#    #+#             */
/*   Updated: 2020/05/13 21:36:32 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s_to;
	unsigned char	*s_from;

	if (!len || (!dst && !src))
		return (dst);
	s_to = (unsigned char *)dst;
	s_from = (unsigned char *)src;
	if (s_to > s_from)
	{
		s_from = s_from + len - 1;
		s_to = s_to + len - 1;
		while (len--)
			*(s_to--) = *(s_from--);
	}
	else
	{
		while (len--)
			*(s_to++) = *(s_from++);
	}
	return (dst);
}
