/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 17:55:18 by alanora           #+#    #+#             */
/*   Updated: 2021/01/24 17:58:03 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** is part of get_word, returns length of one word using indicated divider
*/

int			get_word_add(char **str, char *divider, char *c)
{
	int		step;

	step = 0;
	*c = '\0';
	while ((*str)[step] && (!char_in_array((*str)[step], divider) ||
							*c || !is_work_sym(*str, step)))
	{
		if (!*c && is_work_sym(*str, step) &&
			char_in_array((*str)[step], "\"'"))
			*c = (*str)[step];
		else if (*c == (*str)[step] && (*c == '\'' ||
									is_work_sym(*str, step)))
			*c = '\0';
		step++;
	}
	return (step);
}

/*
** extracts word (smth that is not separated by spaces
** or spaces are in quotes or escaped) from string and shifts
** carriage to the length of this word
** @param string
** @return
*/

char		*get_word(char **str, char *divider)
{
	int		step;
	char	*ret;
	char	c;

	if (!divider)
		divider = " \n\r\f\t\v";
	if (str && *str && **str)
	{
		skip_space(str);
		if (**str)
		{
			step = get_word_add(str, divider, &c);
			ret = ft_strndup(*str, step);
			*str = *str + step;
			skip_space(str);
			return (ret);
		}
	}
	return (NULL);
}

/*
** returns name of variable after $
** @param string
** @param length
** @return
*/

char		*get_env_key(char *str, size_t *length)
{
	int		step;
	char	*ret;

	step = 0;
	*length = 0;
	if (str && *str)
	{
		str++;
		if (char_in_array(str[step], "!@#$^*{}-?"))
			step++;
		else if (str[step] > '0' && str[step] < '9')
			step++;
		else
			while (if_text(str[step]))
				step++;
	}
	ret = NULL;
	if (step)
		ret = ft_strndup(str, step);
	*length = step;
	return (ret);
}
