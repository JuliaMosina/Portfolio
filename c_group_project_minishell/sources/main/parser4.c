/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:55:18 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:58:03 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** deletes one symbol
*/

void		dell_one_char(char **str, size_t step)
{
	while ((*str)[step])
	{
		(*str)[step] = (*str)[step + 1];
		step++;
	}
}

/*
** is part of del_quote, process of deleting symbols
*/

void		del_quote_add(char **str, size_t *step, size_t *step3, char *c)
{
	while ((*str)[*step + *step3] && ((*str)[*step + *step3] != *c))
	{
		if ((*str)[*step + *step3] == '\\' &&
			((*str)[*step + *step3 + 1] == *c ||
			char_in_array((*str)[*step + *step3 + 1], "\\$")))
			(*step3)++;
		(*str)[*step] = (*str)[*step + *step3];
		(*step)++;
	}
}

/*
** deletes quotes
*/

void		del_quote(char **str, size_t *step, size_t *step3)
{
	char	c;

	c = (*str)[*step];
	*step3 = 1;
	if ((*str)[*step] == '\'')
	{
		while ((*str)[*step + *step3] && ((*str)[*step + *step3] != c))
		{
			(*str)[*step] = (*str)[*step + *step3];
			(*step)++;
		}
	}
	else
		del_quote_add(str, step, step3, &c);
}

/*
** is part of dell_slash, deletes step3 - 1 of string from current position
** to delete slashes or quotes
*/

void		dell_slash_add(char **str, size_t *step, size_t *step2,
					size_t *step3)
{
	*step2 = (*step);
	*step3 = (*step3) + 1;
	if ((*str)[*step] && (*str)[(*step) + 1] && (*str)[(*step) + (*step3)])
		while ((*str)[(*step2) + (*step3)])
		{
			(*str)[(*step2)] = (*str)[(*step2) + (*step3)];
			(*step2)++;
		}
	(*str)[*step2] = '\0';
	(*step)--;
}

/*
** cleanups escape characters and functioning quotes
** @param string
*/

void		dell_slash(char **str, char ignore)
{
	size_t	step;
	size_t	step2;
	size_t	step3;
	char	c;

	step = 0;
	if (!str || !*str)
		return ;
	while ((*str)[step])
	{
		if (ignore != '\\' && (*str)[step] == '\\')
			dell_one_char(str, step);
		else if (ignore != '"' && ((*str)[step] == '"' || (*str)[step] == '\'')
		&& (ignore != '\\' || is_work_sym((*str), step)))
		{
			del_quote(str, &step, &step3);
			c = '\0';
			dell_slash_add(str, &step, &step2, &step3);
		}
		step++;
	}
}
