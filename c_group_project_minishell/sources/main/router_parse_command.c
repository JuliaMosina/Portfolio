/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router_parse_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:36:24 by alanora           #+#    #+#             */
/*   Updated: 2021/02/01 17:45:38 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** sets indicated fd into indicated std
*/

void		is_redirect_fd(t_system *minishell, t_command **command,
					int std_fd, int fd)
{
	if (!std_fd)
		(*command)->stdin = set_fd((*command)->stdin,
								minishell->stdin_mine, fd);
	else if (std_fd == 1)
		(*command)->stdout = set_fd((*command)->stdout,
									minishell->stdout_mine, fd);
	else if (std_fd == 2)
		(*command)->stderr = set_fd((*command)->stderr,
									minishell->stderr_mine, fd);
	else if (fd < 0)
		set_status(minishell, 1);
	else
		close(fd);
}

/*
** puts syntax error and sets status
*/

int			is_redirect_syntax_error(t_system *minishell)
{
	system_error_message(minishell, "syntax error near unexpected"
									" token `newline'", NULL, NULL);
	set_status(minishell, 2);
	return (0);
}

/*
** puts to structure type (<>} for >>) and fd number of specified redirection
** work only with second parcing of string
*/

static int	is_redirect(t_system *minishell, char **str, int *i,
					t_command **command)
{
	char	type;
	int		std_fd;
	char	*path;
	int		fd;

	fd = 0;
	type = get_type_from_str(str, i, &std_fd);
	path = get_path_from_str(str, *i);
	if (path)
	{
		word_and_env(minishell, &path);
		dell_slash(&path, '\0');
		(*i)--;
		fd = open_std_file(minishell, path, type);
		is_redirect_fd(minishell, command, std_fd, fd);
		free(path);
	}
	else
		return (is_redirect_syntax_error(minishell));
	*i = *i - 1;
	return (1);
}

/*
** is router for instruments of division string into structure
** depending on control characters found
*/

int			router_parse_command(t_system *minishell, char **str, int *i,
						t_command **command)
{
	if ((*str)[*i])
	{
		if ((*str)[*i] == '#' && (!*i || ((*str)[*i - 1] == ' '
		&& is_work_sym((*str), *i - 1))))
			return (is_hash(minishell, str, i, command));
		else if ((*str)[*i] == ';' && is_work_sym((*str), *i))
			return (is_semicolon(minishell, str, i, command));
		else if (((*str)[*i] == '|') && is_work_sym((*str), *i))
			return (is_pipe(minishell, str, i, command));
		else if (((*str)[*i] == '>' || (*str)[*i] == '<') &&
		is_work_sym((*str), *i))
			return (is_redirect(minishell, str, i, command));
	}
	return (1);
}
