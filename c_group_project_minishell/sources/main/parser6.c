/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser6.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:55:18 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:58:03 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** is part of set_env_to_str, puts value of env element into string
*/

void		set_env_to_str_add(char *env, char *new_str, size_t *step)
{
	size_t	step2;

	step2 = 0;
	while (env[step2])
	{
		new_str[*step] = env[step2];
		(*step)++;
		step2++;
	}
}

/*
** is part of set_env_to_str, copies and counts i symbols
*/

void		set_env_to_str_add2(char **str, char *new_str,
						size_t *step, size_t i)
{
	*step = 0;
	while (*step < i)
	{
		new_str[*step] = (*str)[*step];
		(*step)++;
	}
}

/*
** is part of set_env_to_str, adds part of old string after key to new string
*/

size_t		set_env_to_str_add3(char **str, char *new_str,
							size_t *step, size_t i)
{
	size_t	step2;

	step2 = *step - 1;
	while ((*str)[i])
	{
		new_str[*step] = (*str)[i];
		(*step)++;
		i++;
	}
	new_str[*step] = '\0';
	free(*str);
	*str = new_str;
	return (step2);
}

/*
** is part of set_env_to_str, returns env value from env
*/

char		*set_env_to_str4(t_system *minishell, char **env_key)
{
	char	*env;

	env = NULL;
	if (*env_key)
		env = get_from_env_array(minishell, *env_key);
	if (*env_key)
		free(*env_key);
	if (!env)
		env = "";
	return (env);
}

/*
** sets values of environment variables in string
** @param command
** @param string
** @param i
** @return
*/

size_t		set_env_to_str(t_system *minishell, char **str, size_t i)
{
	size_t	step;
	size_t	key_length;
	char	*env;
	char	*env_key;
	char	*new_str;

	if (is_work_sym(*str, i))
	{
		env_key = get_env_key((*str) + i, &key_length);
		if (key_length)
		{
			env = set_env_to_str4(minishell, &env_key);
			step = ft_strlen(*str) - key_length - i - 1;
			new_str = (char *)malloc(sizeof(char) *
									(i + ft_strlen(env) + 1 + step));
			if (!new_str)
				return (i);
			set_env_to_str_add2(str, new_str, &step, i);
			set_env_to_str_add(env, new_str, &step);
			i = set_env_to_str_add3(str, new_str, &step, i + (key_length + 1));
		}
	}
	return (i);
}
