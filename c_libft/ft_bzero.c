/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 02:17:23 by student           #+#    #+#             */
/*   Updated: 2020/05/14 23:58:01 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	size_t	step;
	char	*rez;

	rez = (char *)s;
	step = 0;
	while (step < n)
	{
		rez[step] = 0;
		step++;
	}
}
