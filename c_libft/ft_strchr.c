/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 03:40:36 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:15:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *rez;

	rez = (char *)s;
	while (*rez && *rez != c)
	{
		rez++;
	}
	if (*rez == c)
		return (rez);
	else
		return (NULL);
}
