/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router_parse_command2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:36:24 by alanora           #+#    #+#             */
/*   Updated: 2021/02/01 17:45:38 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** processes string of command putting it to structure if hash was found
*/

int			is_hash(t_system *minishell, char **str,
					int *i, t_command **command)
{
	*i = *i - skip_space(str);
	(*command)->one_command = ft_strndup((*str), *i);
	if ((*command)->before && (*command)->before->pipe &&
		(!(*command)->one_command || !*((*command)->one_command)))
	{
		system_error_message(minishell, "syntax error near unexpected"
										" token `newline'", NULL, NULL);
		set_status(minishell, 2);
		return (0);
	}
	return (2);
}

/*
** processes string of command putting it to structure if semicolon was found
*/

int			is_semicolon(t_system *minishell, char **str, int *i,
						t_command **command)
{
	*i = *i - skip_space(str);
	if (syntax_error(minishell, ';', *str, *i))
		return (0);
	(*command)->one_command = ft_strndup((*str), *i);
	*command = create_comm_struct(minishell, *command);
	(*str) = (*str) + (*i + 1);
	*i = -1;
	return (1);
}

/*
** is part of is_pipe, writes command down to structures of commands,
** adding flag if this command is source of pipe, creates new structure,
** moves analyzing string
*/

void		is_pipe_add(t_system *minishell, char **str, int *i,
				t_command **command)
{
	(*command)->one_command = ft_strndup((*str), *i);
	(*command)->pipe = 1;
	*command = create_comm_struct(minishell, *command);
	(*str) = (*str) + (*i + 1);
	skip_space(str);
}

/*
** processes string of command putting it to structure if pipe was found
*/

int			is_pipe(t_system *minishell, char **str, int *i,
				t_command **command)
{
	int		fd_pipe[2];

	*i = *i - skip_space(str);
	if (syntax_error(minishell, '|', *str, *i))
		return (0);
	if (pipe(fd_pipe) < 0)
		exit(-1);
	if ((*command)->stdout == minishell->stdout_mine)
		(*command)->stdout = fd_pipe[1];
	else
		close(fd_pipe[1]);
	is_pipe_add(minishell, str, i, command);
	(*command)->stdin = fd_pipe[0];
	if (!**str)
	{
		system_error_message(minishell, "syntax error near unexpected"
										" token `newline'", NULL, NULL);
		set_status(minishell, 2);
		return (0);
	}
	*i = -1;
	return (1);
}
