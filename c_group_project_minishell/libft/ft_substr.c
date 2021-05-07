/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 02:58:28 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:26:04 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	step;
	char	*str;
	char	*substr;

	if (!s)
		return (NULL);
	str = (char *)s;
	step = ft_strlen(str);
	if (start >= step)
		len = 0;
	else if (start + len > step)
		len = step - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	step = 0;
	while (step < len)
	{
		substr[step] = str[start];
		step++;
		start++;
	}
	substr[step] = '\0';
	return (substr);
}
