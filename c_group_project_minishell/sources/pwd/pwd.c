/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:37:21 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:39:03 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** returns address of current location in directory tree
*/

int			incoming_pwd(t_system *minishell, char *str)
{
	char	*pwd;

	if ((pwd = get_pwd()))
	{
		ft_putstr_fd(pwd, minishell->stdout);
		ft_putchar_fd('\n', minishell->stdout);
		free(pwd);
		return (set_status(minishell, 0));
	}
	else
		return (set_status(minishell, 1));
}
