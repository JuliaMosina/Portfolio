/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:30:27 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:31:19 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** modifies the result of work of child process
*/

static int			exec_return_modifier(int ret)
{
	if (ret >= 256)
		ret = ret / 256;
	else
		ret = 0;
	return (ret);
}

/*
** launches exec
** By: bmary: error code output was added for bash compatibility
*/

int					exec_run(t_system *minishell, char *path, char *str)
{
	char			**env;
	char			**words;
	int				ret;
	pid_t			pid;

	ret = 0;
	env = environ_to_array(minishell, 0);
	string_to_words(minishell, &str, &words, 0);
	pid = fork();
	if (!pid)
	{
		execve(path, words, env);
		ret = check_file_and_access(minishell, path, '>');
		free(env);
		free_words(&words);
		minishell->exit = 1;
		return (ret);
	}
	waitpid(pid, &ret, 0);
	free(env);
	free_words(&words);
	error_code_output(minishell, ret);
	return (exec_return_modifier(ret));
}

/*
** checks existence of such file at the address indicated
*/

char				*incoming_exec_add2(char *word, char **path)
{
	char			*full_path;
	int				step;
	int				word_len;

	step = 0;
	full_path = NULL;
	word_len = ft_strlen(word);
	while (!full_path && path[step])
	{
		full_path = check_in_dir(path[step], word, word_len + 1);
		free(path[step]);
		step++;
	}
	while (path[step])
	{
		free(path[step]);
		step++;
	}
	return (full_path);
}

/*
** is part of incoming_exec, takes addresses from key PATH,
** sorts them out and transfers them one by one to incoming_exec_add2
** for checking of existence of the address
*/

int					incoming_exec_add(t_system *minishell, char *str,
						char *word, char *str_orig)
{
	char			**path;
	char			*full_path;
	int				ret;

	ret = 127;
	full_path = get_from_env_array(minishell, "PATH");
	path = NULL;
	if (full_path)
		path = ft_split(full_path, ':');
	if (path)
	{
		full_path = incoming_exec_add2(word, path);
		free(path);
		if (full_path && char_in_array('/', full_path))
			ret = exec_run(minishell, full_path, str_orig);
		if (full_path)
			free(full_path);
	}
	return (ret);
}

/*
** analyses is this direct address or command
** if this is command (it doesn't have / in it's name)
** function searches file with the same name in system directories
** if it findes file of command or it was address of file
** function tries to execute it
*/

int					incoming_exec(t_system *minishell, char *str)
{
	char			*str_orig;
	char			*word;
	int				ret;

	str_orig = str;
	word = get_word(&str, NULL);
	if (!word)
		return (0);
	dell_slash(&word, '\0');
	ret = 127;
	if (char_in_array('/', word))
	{
		ret = exec_run(minishell, word, str_orig);
		free(word);
		return (set_status(minishell, ret));
	}
	ret = incoming_exec_add(minishell, str, word, str_orig);
	if (ret == 127)
		system_error_message(minishell, word, ": command not found", NULL);
	if (word)
		free(word);
	return (set_status(minishell, ret));
}
