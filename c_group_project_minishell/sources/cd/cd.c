/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:24:31 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:25:41 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** puts old address if current is -
*/

int			path_router_history(t_system *minishell)
{
	char	*word;
	char	*word_src;
	int		rez;

	word = get_from_env_array(minishell, "OLDPWD");
	if (word)
	{
		word_src = ft_strdup(word);
		rez = goto_path(minishell, word);
		if (!rez)
		{
			ft_putstr_fd(word_src, minishell->stdout);
			ft_putchar_fd('\n', minishell->stdout);
		}
		free(word_src);
		return (rez);
	}
	system_error_message(minishell, "cd: ", "OLDPWD not set", NULL);
	return (1);
}

/*
** puts home directory instead of ~
*/

int			path_router_home(t_system *minishell)
{
	char	*word;

	word = get_from_env_array(minishell, "HOME");
	if (word)
		return (goto_path(minishell, word));
	system_error_message(minishell, "cd: ", "HOME not set", NULL);
	return (1);
}

/*
** processes string of specified address and in case of finding
** special characters (- ~) changes them to full address
*/

int			path_router(t_system *minishell, char *word)
{
	int		rez;
	int		need_free;

	need_free = 0;
	if (!word || !*word)
		word = "~";
	else if (*word == '~')
	{
		word++;
		if (!*word)
			word = ft_strdup(minishell->home);
		else
			word = ft_strjoin(minishell->home, word);
		need_free = 1;
	}
	if (!ft_strncmp(word, "-", 2))
		return (path_router_history(minishell));
	else if (!ft_strncmp(word, "~", 2))
		return (path_router_home(minishell));
	rez = goto_path(minishell, word);
	if (need_free)
		free(word);
	return (rez);
}

/*
** is part of incoming_cd, fast-forwards to first word
** which exists after all modifications, also takes second word
*/

void		incoming_cd_add(char **str, char **word, char **word_too)
{
	*word = NULL;
	while (*str && **str && !*word)
	{
		*word = get_word(str, NULL);
		if (*word)
			dell_slash(word, '\0');
		if (*word && !**word)
		{
			free(*word);
			*word = NULL;
		}
	}
	if (*word && **word)
		*word_too = get_word(str, NULL);
	else
	{
		*word_too = NULL;
		if (*word)
			free(*word);
		*word = NULL;
	}
}

/*
** takes first argument and transfers it to processing (the rest ignores)
*/

int			incoming_cd(t_system *minishell, char *str)
{
	char	*word;
	char	*word_too;
	int		rez;

	if (minishell->pipe)
		return (set_status(minishell, 0));
	incoming_cd_add(&str, &word, &word_too);
	rez = path_router(minishell, word);
	if (word_too)
		free(word_too);
	if (word)
		free(word);
	return (set_status(minishell, rez));
}
