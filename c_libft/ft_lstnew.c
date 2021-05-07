/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: student <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 23:42:36 by student           #+#    #+#             */
/*   Updated: 2020/05/16 23:56:30 by student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_commands	*ft_lstnew(void *content)
{
	t_commands	*rez;

	rez = (t_commands *)malloc(sizeof(t_commands));
	if (!rez)
		return (NULL);
	rez->content = content;
	rez->next = NULL;
	return (rez);
}
