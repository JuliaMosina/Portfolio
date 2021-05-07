/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:30:27 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:31:19 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** By: bmary: error code output was added for bash compatibility
*/

void				error_code_output(t_system *minishell, int ret)
{
	if (ret == 3)
		ft_putstr_fd("Quit: 3\n", minishell->stdout_mine);
	if (ret == 2)
		ft_putstr_fd("\n", minishell->stdout_mine);
}

/*
** checks existence of file in directory
*/

char				*check_in_dir(char *path, char *command, int command_len)
{
	char			*ret;
	char			*ret_temp;
	DIR				*dir;
	struct dirent	*file;

	ret = NULL;
	if (!(dir = opendir(path)))
		return (NULL);
	while (!ret && (file = readdir(dir)))
	{
		if (!ft_strncmp(file->d_name, command, command_len))
		{
			ret_temp = ft_strjoin(path, "/");
			ret = ft_strjoin(ret_temp, command);
			free(ret_temp);
		}
	}
	closedir(dir);
	return (ret);
}

/*
** returns array of env keys
*/

char				**environ_key_to_array(t_system *minishell)
{
	return (environ_to_array(minishell, 1));
}

/*
** changes the succession env into array of strings
*/

char				**environ_to_array(t_system *minishell, int type)
{
	char			**ret;
	size_t			count;
	size_t			step;
	t_array			*array;

	count = count_in_array(minishell->environ);
	ret = (char**)malloc(sizeof(char *) * (count + 1));
	ret[count] = NULL;
	step = 0;
	array = minishell->environ;
	to_start_array(&array);
	while (array)
	{
		if (type == 1)
			ret[step] = array->key;
		else
			ret[step] = array->value;
		array = array->next;
		step++;
	}
	return (ret);
}

/*
** divides string into arguments
*/

void				string_to_words(t_system *minishell, char **str,
									char ***array, int count)
{
	char			*word;

	word = get_word(str, NULL);
	if (word)
	{
		string_to_words(minishell, str, array, count + 1);
		dell_slash(&word, '\0');
		(*array)[count] = word;
	}
	else
	{
		*array = (char **)malloc(sizeof(char*) * (count + 1));
		(*array)[count] = NULL;
	}
}
