/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 16:28:13 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 16:29:18 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** draw env out from the end of succession to the beginning
** (i.e. reversed succession in reversed order)
*/

int			put_env(t_system *minishell, char *str)
{
	t_array	*env;

	env = minishell->environ;
	to_end_array(&env);
	while (env)
	{
		if (str)
			ft_putstr_fd(str, minishell->stdout);
		ft_putstr_fd(env->value, minishell->stdout);
		ft_putchar_fd('\n', minishell->stdout);
		env = env->before;
	}
	return (set_status(minishell, 0));
}

int			incoming_env(t_system *minishell, char *str)
{
	return (put_env(minishell, ""));
}
