/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 23:34:10 by student           #+#    #+#             */
/*   Updated: 2020/05/14 23:40:58 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			step;
	unsigned char	*rez;

	rez = (unsigned char *)b;
	step = 0;
	while (step < len)
	{
		rez[step] = (unsigned char)c;
		step++;
	}
	return (rez);
}
