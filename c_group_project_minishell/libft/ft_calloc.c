/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 04:36:43 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:00:08 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_calloc(size_t count, size_t size)
{
	void			*rez;
	size_t			step;

	rez = (void *)malloc(size * count);
	if (!rez)
		return (NULL);
	step = 0;
	while (step < count * size)
	{
		((char *)rez)[step] = 0;
		step++;
	}
	return (rez);
}
