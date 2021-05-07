/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 04:49:35 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:23:41 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *rez;
	char *safe;

	rez = (char *)s;
	safe = rez;
	while (*rez)
	{
		if (*rez == c)
			safe = rez;
		rez++;
	}
	if (c == *rez)
		return (rez);
	if (*safe == c)
		return (safe);
	else
		return (NULL);
}
