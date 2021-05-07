/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:01:29 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:14:33 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** extracts name of command and transfers control to appropriate function
*/

void			main_parser(t_system *minishell, char *str)
{
	int			(*function)(t_system *, char *);
	char		*key;
	char		*src_str;

	if (!str)
		return ;
	src_str = str;
	key = get_key_command(minishell, &str);
	if (!key)
		return ;
	dell_slash(&key, '\0');
	function = NULL;
	if (key && ft_strncmp(key, "exec", 5))
		function = get_from_array(minishell->commands, key);
	if (!function)
	{
		function = get_from_array(minishell->commands, "exec");
		str = src_str;
	}
	if (function)
		function(minishell, str);
	if (key)
		free(key);
}

/*
** reads from keyboard's descriptor or fd one string by one
** and transfers to parcing
*/

void			main_reader(t_system *minishell)
{
	char		*str;
	char		*str_temp;

	str = NULL;
	while (!minishell->exit && 0 < get_next_input(minishell, &str))
	{
		str_temp = ft_strdup(str);
		parse_str_and_run(minishell, str);
		free(str_temp);
		if (str)
			free(str);
		str = NULL;
	}
	set_std_default(minishell);
	if (str)
		free(str);
	str = NULL;
}

/*
** nulls or sets default values of variables for work of programme
*/

void			set_default(t_system *minishell, char **env)
{
	minishell->stdin_mine = dup(0);
	minishell->stdout_mine = dup(1);
	minishell->stderr_mine = dup(2);
	minishell->is_keyboard = 1;
	minishell->exit = 0;
	minishell->status = 0;
	minishell->status_in_str = 0;
	minishell->status_str = NULL;
	minishell->status_message = NULL;
	minishell->commands = NULL;
	minishell->environ = NULL;
	minishell->local = get_pwd();
	set_env(minishell, env);
	set_commands(&minishell->commands);
	minishell->home = get_from_env_array(minishell, "HOME");
	if (minishell->home && !*(minishell->home))
		minishell->home = NULL;
	else
		minishell->home = ft_strdup(minishell->home);
	minishell->stdin = minishell->stdin_mine;
	set_std_in_variable(minishell, 'i', minishell->stdin_mine);
	minishell->stdout = minishell->stdout_mine;
	set_std_in_variable(minishell, 'o', minishell->stdout_mine);
	minishell->stderr = minishell->stderr_mine;
	set_std_in_variable(minishell, 'e', minishell->stderr_mine);
}

/*
** works with signals
*/

void			handler_c(int sig)
{
}

/*
** launches minishell
*/

int				minishell_run(int argc, char **argv, char **env)
{
	t_system	minishell;

	signal(SIGINT, handler_c);
	signal(SIGQUIT, handler_c);
	set_default(&minishell, env);
	minishell.argc = argc - 2;
	minishell.argv = argv + 1;
	if (argc > 1)
	{
		minishell.stdin = open(argv[1], O_RDONLY);
		if (minishell.stdin < 0)
		{
			system_error_message(&minishell, argv[1],
						" No such file or directory", NULL);
			sys_destroy(&minishell);
			return (127);
		}
		minishell.is_keyboard = 0;
		minishell.stdin_mine = minishell.stdin;
	}
	main_reader(&minishell);
	if (!is_keyboard(&minishell))
		close(minishell.stdin);
	sys_destroy(&minishell);
	return (minishell.status);
}
