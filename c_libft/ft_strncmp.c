/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:28:06 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:48:20 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			step;
	unsigned char	*str1;
	unsigned char	*str2;
	int				ret;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	step = 0;
	if (!n)
		return (0);
	while (str1[step] == str2[step] && str1[step] && str2[step]
			&& step < (n - 1))
		step++;
	if (str1[step] == '\0' && str2[step] == '\0')
		return (0);
	else
	{
		ret = str1[step] - str2[step];
		return (ret);
	}
}
