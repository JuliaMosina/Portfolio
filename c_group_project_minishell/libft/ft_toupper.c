/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:28:43 by student           #+#    #+#             */
/*   Updated: 2020/05/16 20:27:31 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	int	d;

	if (c >= 97 && c <= 122)
	{
		d = c - 32;
		return (d);
	}
	else
		return (c);
}
