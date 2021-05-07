/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 10:05:09 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:19:10 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	step;
	char			*rez;
	char			*str;

	str = (char *)s;
	step = 0;
	if (!str)
		return (NULL);
	while (str[step])
		step++;
	rez = (char *)malloc(sizeof(char) * (step + 1));
	if (!rez)
		return (NULL);
	step = 0;
	while (str[step])
	{
		rez[step] = f(step, str[step]);
		step++;
	}
	rez[step] = '\0';
	return (rez);
}
