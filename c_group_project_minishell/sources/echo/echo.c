/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:26:15 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:27:31 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** puts word by word to stdout
*/

static void	echo_out_words(t_system *minishell, char *str, char *word)
{
	int		first;

	first = 1;
	while (word)
	{
		if (!first)
			ft_putchar_fd(' ', minishell->stdout);
		else
			first = 0;
		if (*word)
			ft_putstr_fd(word, minishell->stdout);
		free(word);
		word = get_word(&str, NULL);
		dell_slash(&word, '\0');
	}
}

/*
** divides command echo into "words", changes variables and deletes commas and
** slashes into words using appropriate functions
*/

int			incoming_echo(t_system *minishell, char *str)
{
	int		end_break;
	char	*word;

	end_break = 1;
	word = get_word(&str, NULL);
	dell_slash(&word, '\0');
	while (word && !ft_strncmp(word, "-n", 3))
	{
		free(word);
		end_break = 0;
		word = get_word(&str, NULL);
		dell_slash(&word, '\0');
	}
	echo_out_words(minishell, str, word);
	if (end_break)
		ft_putchar_fd('\n', minishell->stdout);
	return (set_status(minishell, 0));
}
