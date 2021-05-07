/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 05:51:11 by student           #+#    #+#             */
/*   Updated: 2020/05/09 06:32:14 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_nbr(int n, int fd)
{
	int		step;
	char	sym;

	step = n / 10;
	if (step > 0)
		ft_nbr(step, fd);
	sym = '0' + n % 10;
	write(fd, &sym, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	sym;

	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n / 10)
			ft_nbr((n / 10) * -1, fd);
		sym = '0' + (n % 10) * -1;
		write(fd, &sym, 1);
	}
	else
		ft_nbr(n, fd);
}
