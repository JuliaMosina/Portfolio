/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:35:04 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:36:17 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** is part of get_next_word, gathers string key=value
*/

void		get_next_word_add(t_system *minishell, char **str,
						char **word, int step)
{
	char	*key;
	char	*new_str;

	key = ft_strndup(*word, step);
	dell_slash(&key, '\0');
	if (!(new_str = homework(minishell, *word + (step + 1), 0)))
		new_str = ft_strdup(*word + (step + 1));
	free(*word);
	*word = ft_strjoin("=", new_str);
	free(new_str);
	new_str = ft_strjoin(key, *word);
	free(*word);
	free(key);
	*word = new_str;
	dell_slash(word, '\\');
}

/*
** processes pairs key=value (as they can be composite)
*/

char		*get_next_word(t_system *minishell, char **str)
{
	char	*word;
	int		step;

	word = get_word(str, NULL);
	if (!word)
		return (word);
	step = 0;
	while (word[step] && word[step] != '=')
		step++;
	if (word[step] == '=')
		get_next_word_add(minishell, str, &word, step);
	else
		dell_slash(&word, '\0');
	return (word);
}

/*
** is part of incoming_export, divides string into words (key=value) and
** transfers for recording analyzing rezult (is there mistakes or not)
*/

int			incoming_export_add(t_system *minishell, char *str,
						char *word, int *argc)
{
	char	*word_no_space;
	int		ret;

	ret = 0;
	while (str && (word = get_next_word(minishell, &str)))
	{
		word_no_space = word;
		skip_space(&word_no_space);
		if (word_no_space && *word_no_space)
		{
			(*argc)++;
			if (write_env_unit(minishell, word))
			{
				ret = 1;
				system_error_message(minishell, "export: `",
									word, "': not a valid identifier");
			}
		}
		free(word);
	}
	return (ret);
}

/*
** adds to or changes elements of succession env
*/

int			incoming_export(t_system *minishell, char *str)
{
	char	*word;
	int		ret;
	int		argc;

	ret = 0;
	argc = 0;
	skip_space(&str);
	if (minishell->pipe)
		return (set_status(minishell, 0));
	if (str && *str)
		ret = incoming_export_add(minishell, str, word, &argc);
	if (!argc)
		return (put_export(minishell));
	return (set_status(minishell, ret));
}
