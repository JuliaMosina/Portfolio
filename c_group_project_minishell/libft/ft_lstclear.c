/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 04:45:27 by student           #+#    #+#             */
/*   Updated: 2020/05/17 05:05:55 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_commands **lst, void (*del)(void *))
{
	t_commands	*targ;
	t_commands	*step;

	if (!lst || !del)
		return ;
	if (!*lst)
		return ;
	targ = *lst;
	while (targ)
	{
		step = targ;
		targ = step->next;
		ft_lstdelone(step, del);
	}
	*lst = NULL;
}
