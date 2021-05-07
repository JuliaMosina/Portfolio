/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 04:22:51 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:17:39 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*n_s(char *new_str, char *str1, char *str2)
{
	size_t	step;
	size_t	safe_step;

	step = 0;
	while (str1[step])
	{
		new_str[step] = str1[step];
		step++;
	}
	safe_step = step;
	step = 0;
	while (str2[step])
	{
		new_str[safe_step] = str2[step];
		safe_step++;
		step++;
	}
	new_str[safe_step] = '\0';
	return (new_str);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	size_t	step;
	size_t	safe_step;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	str1 = (char *)s1;
	str2 = (char *)s2;
	step = 0;
	while (str1[step])
		step++;
	safe_step = step;
	step = 0;
	while (str2[step])
		step++;
	new_str = (char *)malloc(sizeof(char) * (safe_step + step + 1));
	if (!new_str)
		return (NULL);
	new_str = n_s(new_str, str1, str2);
	return (new_str);
}
