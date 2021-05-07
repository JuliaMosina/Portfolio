/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:01:29 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:14:33 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** buffer between functions minishell and gnl, changes status
** of last non void inputed string to 1 if it was reading from file
** and changes last empty string to exit if it was reading from keyboard
*/

int				get_next_line_buffer(t_system *minishell, int fd, char **str)
{
	int			rez;

	if (!(rez = get_next_line(fd, str)))
	{
		if (!*str || !**str)
		{
			if (is_keyboard(minishell))
			{
				if (*str)
					free(*str);
				*str = ft_strdup("exit");
				rez = 1;
			}
		}
		else if (**str && !is_keyboard(minishell))
			rez = 1;
	}
	return (rez);
}

/*
** searches or creates element of succession and with the appropriate function
** writes the link to transferred function down in it
*/

int				set_commands_to_array(t_array **array, char *key,
										int (*function)(t_system *, char *))
{
	t_array		*temp;

	temp = set_null_to_array(array, key);
	temp->value = function;
	return (1);
}

/*
** matches commands with functions processing them in succession command
*/

void			set_commands(t_array **array)
{
	set_commands_to_array(array, "echo", incoming_echo);
	set_commands_to_array(array, "env", incoming_env);
	set_commands_to_array(array, "pwd", incoming_pwd);
	set_commands_to_array(array, "export", incoming_export);
	set_commands_to_array(array, "unset", incoming_unset);
	set_commands_to_array(array, "cd", incoming_cd);
	set_commands_to_array(array, "exec", incoming_exec);
	set_commands_to_array(array, "exit", incoming_exit);
}

/*
** returns name of command or launches parcing if command
** was composed or in a variable
*/

char			*get_key_command(t_system *minishell, char **str)
{
	char		*key;

	skip_space(str);
	key = get_word(str, NULL);
	if (!key || !*key)
		return (key);
	return (key);
}

/*
** requests string from keyboard or fd
*/

int				get_next_input(t_system *minishell, char **str)
{
	if (is_keyboard(minishell))
		ft_putstr_fd("minishell$ ", minishell->stdout);
	return (get_next_line_buffer(minishell, minishell->stdin, str));
}
