/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:41:26 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:42:58 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** deletes variable from the succession env
*/

int			incoming_unset(t_system *minishell, char *str)
{
	char	*word;
	int		ret;

	if (minishell->pipe)
		return (set_status(minishell, 0));
	ret = 0;
	if (str)
	{
		while (str && (word = get_word(&str, NULL)))
		{
			dell_slash(&word, '\0');
			if (check_env_key(word))
			{
				ret = 1;
				system_error_message(minishell, "unset: `",
						word, "': not a valid identifier");
			}
			else
				delete_in_array(&minishell->environ, word);
			free(word);
		}
	}
	return (set_status(minishell, ret));
}
