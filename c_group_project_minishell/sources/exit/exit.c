/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:32:47 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:34:52 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** takes indicated exit status and checks it, if it is valid (numerals)
** sets it as current, if is not valid puts error message
*/

int			exit_parser_word(t_system *minishell, char *str, char *word)
{
	int		ret;
	int		step;

	ret = minishell->status;
	if (word && *word)
	{
		step = 0;
		while (word[step])
			if (word[step] >= '0' && word[step] <= '9')
				step++;
			else
			{
				system_error_message(minishell, "exit: ",
									word, ": numeric argument required");
				return (set_status(minishell, 2));
			}
		ret = ft_atoi(word);
	}
	return (ret);
}

/*
** executes the escape from programme with setting exit flag
*/

int			incoming_exit(t_system *minishell, char *str)
{
	char	*word;
	int		ret;

	if (!is_keyboard(minishell))
		close(minishell->stdin);
	minishell->exit = 1;
	ft_putstr_fd("exit\n", 1);
	word = get_word(&str, NULL);
	ret = exit_parser_word(minishell, str, word);
	if (word)
		free(word);
	return (set_status(minishell, ret));
}
