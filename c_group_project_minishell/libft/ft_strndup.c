/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:58:16 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:59:59 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t max)
{
	size_t	step;
	size_t	len;
	char	*s2;

	len = 0;
	while (s1[len])
		len++;
	if (len > max)
		len = max;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	step = 0;
	while (step < len)
	{
		s2[step] = s1[step];
		step++;
	}
	s2[step] = '\0';
	return (s2);
}
