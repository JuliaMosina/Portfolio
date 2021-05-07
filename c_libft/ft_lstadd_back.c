/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 03:11:25 by student           #+#    #+#             */
/*   Updated: 2020/05/17 03:38:56 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_commands **lst, t_commands *new)
{
	t_commands	*targ;

	if (!new || !lst)
		return ;
	targ = *lst;
	if (!targ)
		*lst = new;
	else
	{
		while (targ && targ->next)
			targ = targ->next;
		targ->next = new;
	}
}
