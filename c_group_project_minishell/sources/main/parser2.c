/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:55:18 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:58:03 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** works with ~
*/

char		*homework(t_system *minishell, char *str, int i)
{
	int		step;
	char	*new_str;
	char	*new_str2;

	step = i;
	if (str[step] == '~' && (!step || str[step - 1] == ' '))
	{
		step++;
		if (!str[step] || char_in_array(str[step], " \n\r\f\t\v/"))
		{
			new_str2 = ft_strndup(str, i);
			new_str = ft_strjoin(new_str2, minishell->home);
			free(new_str2);
			new_str2 = ft_strjoin(new_str, str + (i + 1));
			free(new_str);
			return (new_str2);
		}
	}
	return (NULL);
}

/*
** fast-forwards string through skipping space characters
*/

int			skip_space(char **str)
{
	int		step;

	step = 0;
	if (str && *str)
		while (char_in_array(**str, " \n\r\f\t\v"))
		{
			(*str)++;
			step++;
		}
	return (step);
}

/*
** checks existence of symbol in succession
*/

int			char_in_array(char c, char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == c)
				return (1);
			str++;
		}
	}
	return (0);
}

/*
** counts slashes before symbol number in string of which comes in variable i
** and returns 1 - even (symbol isn't escaped, i.e. working), 0 - odd
** @param str
** @param i
** @return
*/

int			is_work_sym(char *str, size_t i)
{
	int		step;

	step = 1;
	if (i)
		while ((int)i - step >= 0 && str[i - step] == '\\')
			step++;
	step--;
	if (!(step % 2))
		return (1);
	else
		return (0);
}

/*
** if _ or a-z or A-Z or 0-9 returns 1
** @param c
** @return
*/

short int	if_text(char c)
{
	if (c == '_' || (c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
