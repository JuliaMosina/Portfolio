/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:44:19 by alanora           #+#    #+#             */
/*   Updated: 2021/02/01 01:52:05 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** creates structure where command separated from string is saved
*/

t_command		*create_comm_struct(t_system *minishell, t_command *command)
{
	t_command	*unit;

	unit = (t_command *)malloc(sizeof(t_command));
	unit->pipe = 0;
	unit->one_command = NULL;
	unit->stdin = minishell->stdin_mine;
	unit->stdout = minishell->stdout_mine;
	unit->stderr = minishell->stderr_mine;
	unit->before = command;
	unit->next = NULL;
	if (command)
		command->next = unit;
	return (unit);
}

/*
** throw fds off by default
*/

void			close_fd_comm_struct(t_system *minishell, t_command **command)
{
	if ((*command)->stdin > 2 && (*command)->stdin != minishell->stdin_mine)
		close((*command)->stdin);
	(*command)->stdin = minishell->stdin_mine;
	if ((*command)->stdout > 2 && (*command)->stdout != minishell->stdout_mine)
		close((*command)->stdout);
	(*command)->stdout = minishell->stdout_mine;
	if ((*command)->stderr > 2 && (*command)->stderr != minishell->stderr_mine)
		close((*command)->stderr);
	(*command)->stderr = minishell->stderr_mine;
}

/*
** deletes the succession of structures where commands from string are saved
*/

void			del_comm_struct(t_system *minishell, t_command **command)
{
	t_command	*next;

	while ((*command)->before)
		*command = (*command)->before;
	while (*command)
	{
		next = (*command)->next;
		if ((*command)->one_command)
			free((*command)->one_command);
		close_fd_comm_struct(minishell, command);
		free((*command));
		*command = next;
	}
}

/*
** sets in out and error fds according to fds from command
*/

int				set_std_from_command(t_system *minishell, t_command *command)
{
	set_std_in_variable(minishell, 'i', command->stdin);
	set_std_in_variable(minishell, 'o', command->stdout);
	set_std_in_variable(minishell, 'e', command->stderr);
	if (command->stdin < 0 || command->stdout < 0 || command->stderr < 0)
	{
		return (0);
	}
	return (1);
}

/*
** launches command from structure, processing fd previously
*/

void			run_comm_struct(t_system *minishell, t_command *command)
{
	char		*one_command;

	while (command->before)
		command = command->before;
	while (!minishell->exit && command)
	{
		one_command = ft_strdup(command->one_command);
		if (parse_str_to_command(minishell, one_command, &command,
						"><") && set_std_from_command(minishell, command))
		{
			if (one_command)
			{
				minishell->pipe = command->pipe;
				word_and_env(minishell, &one_command);
				main_parser(minishell, one_command);
				close_fd_comm_struct(minishell, &command);
			}
		}
		else
			set_status(minishell, 1);
		set_std_default(minishell);
		if (one_command)
			free(one_command);
		command = command->next;
	}
}
