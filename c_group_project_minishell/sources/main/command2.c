/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 02:17:12 by alanora           #+#    #+#             */
/*   Updated: 2021/02/01 02:29:36 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** fast-forwards string for one word
*/

int				parse_str_skip_words(char *str, int i, char *c, char *divider)
{
	*c = '\0';
	while (str[i] && (*c || !char_in_array(str[i], divider)))
	{
		if ((str[i] == *c || (!*c && char_in_array(str[i], "'\""))) &&
			(*c == '\'' || is_work_sym(str, i)))
		{
			if (*c)
				*c = '\0';
			else
				*c = str[i];
		}
		i++;
	}
	return (i);
}

/*
** checks value of variable which saves quote (empty or not)
*/

int				check_c(t_system *minishell, char c)
{
	char		*str;

	if (c)
	{
		if (c == '"')
			str = "\"";
		else
			str = "'";
		system_error_message(minishell, "unexpected end of string while"
								" looking for matching `", str, "'");
		set_status(minishell, 2);
		return (0);
	}
	return (1);
}

/*
** parses string (to get separated commands)
*/

int				parse_str_to_command(t_system *minishell, char *str,
							t_command **command, char *divider)
{
	int			i;
	int			rez;
	char		c;

	if (!str)
		return (1);
	c = '\0';
	i = 0;
	while (i >= 0 && str && str[i])
	{
		i = parse_str_skip_words(str, i, &c, divider);
		if ((rez = router_parse_command(minishell, &str, &i, command)) != 1)
			return (rez);
		if (i < 0 || str[i])
			i++;
	}
	if (!check_c(minishell, c))
		return (0);
	i = i - skip_space(&str);
	if (i > 0 && (*command)->one_command)
		free((*command)->one_command);
	if (i > 0)
		(*command)->one_command = ft_strdup(str);
	return (1);
}

/*
** parces string to commands and in case of non finding syntax errors
** executes succession of commands
*/

void			parse_str_and_run(t_system *minishell, char *str)
{
	t_command	*command_array;

	command_array = create_comm_struct(minishell, NULL);
	if (parse_str_to_command(minishell, str, &command_array, ";#|"))
		run_comm_struct(minishell, command_array);
	del_comm_struct(minishell, &command_array);
}
