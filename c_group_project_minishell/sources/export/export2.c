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
** returns min value
*/

int			print_env_min(int v1, int v2)
{
	if (v1 < v2)
		return (v1);
	else
		return (v2);
}

/*
** puts env element
*/

void		print_env_bmary(t_system *minishell, char **env)
{
	char	**first;

	first = env;
	while (*first != NULL)
	{
		ft_putstr_fd("declare -x ", minishell->stdout);
		ft_putstr_fd(*first, minishell->stdout);
		ft_putstr_fd("=\"", minishell->stdout);
		ft_putstr_fd(get_from_env_array(minishell, *first), minishell->stdout);
		ft_putstr_fd("\"\n", minishell->stdout);
		first++;
	}
}

/*
** sorts key array out
*/

void		sort_env(char **array)
{
	int		i;
	int		j;
	int		min_len;
	char	*swap;

	i = 0;
	while (array[i] != NULL)
	{
		j = i + 1;
		while (array[j] != NULL)
		{
			min_len = print_env_min(ft_strlen(array[i]),
						ft_strlen(array[j])) + 1;
			if (ft_strncmp(array[i], array[j], min_len) > 0)
			{
				swap = array[i];
				array[i] = array[j];
				array[j] = swap;
			}
			j++;
		}
		i++;
	}
}

/*
** is function-mediator, puts env
*/

int			put_export(t_system *minishell)
{
	char	**env;

	env = environ_key_to_array(minishell);
	sort_env(env);
	print_env_bmary(minishell, env);
	free(env);
	return (set_status(minishell, 0));
}
