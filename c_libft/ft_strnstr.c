/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 05:28:32 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:21:38 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*rez1;
	char	*rez2;
	size_t	step;
	size_t	safe_st;

	rez1 = (char *)haystack;
	rez2 = (char *)needle;
	step = 0;
	while (*rez1 && step++ < len)
	{
		safe_st = step;
		while (*rez2 && *(rez1++) == *rez2 && step++ <= len)
			rez2++;
		if (!*rez2)
			return ((char *)haystack + (safe_st - 1));
		else
			rez2 = (char *)needle;
		rez1 = (char *)haystack + safe_st;
		step = safe_st;
	}
	if (!*rez2)
		return (rez1);
	return (NULL);
}
