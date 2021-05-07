/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 05:46:11 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:16:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	step;
	size_t	len;
	char	*s2;

	if (!s1)
		return (NULL);
	len = 0;
	while (s1[len])
		len++;
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
