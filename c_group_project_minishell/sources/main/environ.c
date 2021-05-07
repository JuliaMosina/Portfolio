/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:29:37 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:44:09 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** creates and writes down key and value of element of succession env
** received from key and value transferred separately
*/

void		set_env_value(t_system *minishell, char *key, char *value)
{
	char	*env_key;
	char	*env;

	env_key = ft_strjoin(key, "=");
	env = ft_strjoin(env_key, value);
	if (env_key)
		free(env_key);
	set_str_to_array(&minishell->environ, key, env);
	if (env)
		free(env);
}

/*
** checks validity of env key (can not start with numeral)
*/

int			check_env_key(char *str)
{
	int		rez;

	rez = 1;
	skip_space(&str);
	if (str && *str && ((*str >= 'a' && *str <= 'z') ||
	(*str >= 'A' && *str <= 'Z') || *str == '_'))
	{
		rez = 0;
	}
	return (rez);
}

/*
** extracts key of succession env and its length and
** creates or changes appropriate element in succession env
*/

int			write_env_unit(t_system *minishell, char *str)
{
	char	*key;
	int		step;

	step = 0;
	while (str[step] && str[step] != '=')
		step++;
	if (str[step] == '=')
	{
		key = ft_strndup(str, step);
		if (check_env_key(key))
		{
			free(key);
			return (1);
		}
		set_str_to_array(&(minishell->environ), key, str);
		free(key);
	}
	else
	{
		if (check_env_key(str))
			return (1);
	}
	return (0);
}

/*
** transfers value from array of strings to succession env
** in variable shlvl is level of launching programme (shell level)
*/

void		set_env(t_system *minishell, char **env)
{
	int		step;
	char	*shlvl;

	step = 0;
	while (env[step])
	{
		write_env_unit(minishell, env[step]);
		step++;
	}
	shlvl = get_from_env_array(minishell, "SHLVL");
	if (shlvl)
	{
		step = ft_atoi(shlvl) + 1;
		shlvl = ft_itoa(step);
		set_str_to_array(&(minishell->environ), "SHLVL", shlvl);
		free(shlvl);
	}
}

/*
** returns value of found element of succession env with deleted key= from it
*/

char		*get_from_env_array(t_system *minishell, char *key)
{
	t_array	*rez;
	int		temp;

	if (key)
	{
		if (key[0] && !key[1])
		{
			if (key[0] == '?')
				return (get_status(minishell));
			if (key[0] >= '0' && key[0] <= '9')
			{
				temp = key[0] - '0';
				if (minishell->argc >= temp)
					return (minishell->argv[temp]);
				return ("");
			}
		}
		rez = find_in_array(minishell->environ, key);
		if (rez)
			return (rez->value + rez->key_length + 1);
	}
	return (NULL);
}
