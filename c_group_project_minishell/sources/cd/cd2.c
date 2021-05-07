/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:24:31 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:25:41 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** makes transition to address (changes focus directory to needed one)
** and displays errors
*/

int			goto_path(t_system *minishell, char *path)
{
	char	*pwd;
	int		rez;

	rez = chdir(path);
	if (rez)
	{
		system_error_message(minishell, "cd: ", path,
							": No such file or directory");
		return (rez);
	}
	pwd = get_from_env_array(minishell, "PWD");
	if (pwd)
		set_env_value(minishell, "OLDPWD", pwd);
	else
		delete_in_array(&minishell->environ, "OLDPWD");
	pwd = get_pwd();
	set_env_value(minishell, "PWD", pwd);
	free(pwd);
	return (rez);
}
