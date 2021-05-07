/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:47:26 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:52:08 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** is part of check_file_and_access, contains check itself
*/

int			check_file_and_access_add(t_system *minishell, char *path,
								DIR *dir, int fd)
{
	int		ret;

	ret = 126;
	if (dir == NULL)
	{
		if (fd == -1)
		{
			system_error_message(minishell, path,
								": No such file or directory", NULL);
			ret = 127;
		}
		else
			system_error_message(minishell, path, ": Permission denied", NULL);
	}
	else if (fd == -1)
		system_error_message(minishell, path, ": is a directory", NULL);
	else
		ret = 0;
	return (ret);
}

/*
** checks existence of file and access rights
*/

int			check_file_and_access(t_system *minishell, char *path, char type)
{
	DIR		*dir;
	int		fd;
	int		ret;

	dir = opendir(path);
	if (type == '<')
		fd = open(path, O_RDONLY);
	else
		fd = open(path, O_WRONLY);
	ret = check_file_and_access_add(minishell, path, dir, fd);
	if (dir)
		closedir(dir);
	if (fd > 0)
		close(fd);
	return (ret);
}
