/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:47:26 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:52:08 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** sets transferred fd to specified stream
*/

void		set_std_in_variable(t_system *minishell, char type, int fd)
{
	if (type == 'i')
	{
		minishell->stdin = set_fd(minishell->stdin, minishell->stdin_mine, fd);
		dup2(minishell->stdin, 0);
	}
	else if (type == 'o')
	{
		minishell->stdout = set_fd(minishell->stdout,
							minishell->stdout_mine, fd);
		dup2(minishell->stdout, 1);
	}
	else if (type == 'e')
	{
		minishell->stderr = set_fd(minishell->stderr,
							minishell->stderr_mine, fd);
		dup2(minishell->stderr, 2);
	}
}

/*
** gets location in directory tree
*/

char		*get_pwd(void)
{
	char	pwd[BUFFER_SIZE];

	if (getcwd(pwd, BUFFER_SIZE))
		return (ft_strdup(pwd));
	return (NULL);
}

/*
** closes old fd in case it wasn't standard one and was changed, returns new fd
*/

int			set_fd(int old_fd, int def_fd, int new_fd)
{
	if (old_fd != def_fd && old_fd > 2)
		close(old_fd);
	return (new_fd);
}

/*
** opens fd and sets in one of standard ones
*/

int			open_std_file(t_system *minishell, char *filename, char type)
{
	int		new_fd;

	if (type == '>')
		new_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else if (type == '}')
		new_fd = open(filename, O_CREAT | O_WRONLY | O_APPEND,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	else
		new_fd = open(filename, O_RDONLY,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (new_fd < 0)
		set_status(minishell, check_file_and_access(minishell, filename, type));
	return (new_fd);
}

/*
** if fds are not equal to on default sets them on default
*/

void		set_std_default(t_system *minishell)
{
	minishell->pipe = 0;
	if (minishell->stdin != minishell->stdin_mine)
		set_std_in_variable(minishell, 'i', minishell->stdin_mine);
	if (minishell->stdout != minishell->stdout_mine)
		set_std_in_variable(minishell, 'o', minishell->stdout_mine);
	if (minishell->stderr != minishell->stderr_mine)
		set_std_in_variable(minishell, 'e', minishell->stderr_mine);
}
