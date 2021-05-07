/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:55:18 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:58:03 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** is part of word_and_env, выставляет или удаляет знак кавычки одинарной
*/

char		word_and_env_add1(char **str, int step, char c)
{
	if (is_work_sym(*str, step) && !c)
		return ((*str)[step]);
	else
		return ('\0');
}

/*
** is part of word_and_env, выставляет или удаляет знак кавычки одинарной
*/

char		word_and_env_add2(char **str, int step, char c)
{
	if (is_work_sym(*str, step))
	{
		if (!c)
			return ((*str)[step]);
		else
			return ('\0');
	}
	return (c);
}

/*
** is part of word_and_env, cuts string if hash (#) is working symbol
*/

int			word_and_env_add3(char **str, int step, char c)
{
	char	*new_str;

	if ((!step || (*str)[step - 1] == ' ') && !c)
	{
		new_str = ft_strndup(*str, step);
		free(*str);
		*str = new_str;
		return (1);
	}
	return (0);
}

/*
** is part of word_and_env, transfers ~ for replacement if are not in quotes
*/

void		word_and_env_add4(t_system *minishell, char **str, int step, char c)
{
	char	*new_str;

	if (!c && (new_str = homework(minishell, *str, step)))
	{
		free(*str);
		*str = new_str;
	}
}

/*
** moves in word and transfers all variables which are not in single quotes
** to function set_env_to_str, in case of finding non escaped hash cuts string
** @param command
** @param string
** @return
*/

int			word_and_env(t_system *minishell, char **str)
{
	int		step;
	char	c;

	step = 0;
	c = '\0';
	if (!str || !*str)
		return (0);
	while (*str && (*str)[step])
	{
		word_and_env_add4(minishell, str, step, c);
		if ((*str)[step] == '$' && c != '\'')
			step = set_env_to_str(minishell, str, step);
		else if ((*str)[step] == '\'' && c != '"')
			c = word_and_env_add1(str, step, c);
		else if ((*str)[step] == '"' && c != '\'')
			c = word_and_env_add2(str, step, c);
		else if ((*str)[step] == '#' && word_and_env_add3(str, step, c))
			return (1);
		step++;
	}
	return (0);
}
