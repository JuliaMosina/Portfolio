/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:01:29 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:14:33 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** determines input is from file or keyboard
*/

int				is_keyboard(t_system *minishell)
{
	return (minishell->is_keyboard);
}

/*
** sets status of the last execution of command to the main structure
*/

int				set_status(t_system *minishell, int status)
{
	minishell->status = status;
	return (status);
}

/*
** returns status of the previous executed command as string
*/

char			*get_status(t_system *minishell)
{
	if (!minishell->status_str || minishell->status != minishell->status_in_str)
	{
		if (minishell->status_str)
			free(minishell->status_str);
		minishell->status_in_str = minishell->status;
		minishell->status_str = ft_itoa(minishell->status_in_str);
	}
	return (minishell->status_str);
}

/*
** cleanups all before end of programme's work
*/

void			sys_destroy(t_system *minishell)
{
	if (minishell->status_str)
		free(minishell->status_str);
	if (minishell->home)
		free(minishell->home);
	if (minishell->local)
		free(minishell->local);
	destroy_array(&(minishell->commands));
	destroy_array(&(minishell->environ));
}
