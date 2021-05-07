/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   router_parse_command3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 17:36:24 by alanora           #+#    #+#             */
/*   Updated: 2021/02/01 17:45:38 by alanora          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
** defines indicated fd before sign of redirection
*/

int			get_type_from_str_start(char **str, int *i, int *fd)
{
	int		start;

	start = *i - 1;
	while (start >= 0 && (*str)[start] >= '0' && (*str)[start] <= '9')
		start--;
	if (start < 0 || (char_in_array((*str)[start], " \n\r\f\t\v\"'")
					&& is_work_sym((*str), start)))
	{
		start++;
		if (start != *i)
			*fd = ft_atoi((*str) + start);
	}
	else
		start = *i;
	return (start);
}

/*
** defines fd on default for redirection and type of redirection
*/

void		get_double_type(char **str, int *i, int *fd, char *type)
{
	if (*fd == -1 && *type == '>')
		*fd = 1;
	else if (*fd == -1 && *type == '<')
		*fd = 0;
	if ((*str)[*i] == (*str)[*i + 1])
	{
		if (*type == '<')
			*type = '<';
		else
			*type = '}';
		(*i)++;
	}
}

/*
** returns type (<>} for >>) and fd number of specified redirection output
*/

char		get_type_from_str(char **str, int *i, int *fd)
{
	char	type;
	int		y;
	int		start;

	if (!str || !*str)
		return ('\0');
	*fd = -1;
	type = (*str)[*i];
	start = *i;
	if (*i > 0)
		start = get_type_from_str_start(str, i, fd);
	get_double_type(str, i, fd, &type);
	y = (*i) + 1;
	*i = start;
	while ((*str)[y])
		(*str)[start++] = (*str)[y++];
	(*str)[start] = '\0';
	return (type);
}

/*
** returns name of file (destination of input output redirections) from string
*/

char		*get_path_from_str(char **str, int i)
{
	char	*path;
	int		len;
	int		y;

	len = 0;
	path = (*str) + i;
	i = i + skip_space(&path);
	path = get_word(&path, " \n\r\f\t\v|;><");
	if (path)
		len = ft_strlen(path);
	if (len)
	{
		y = i + len;
		while ((*str)[y])
			(*str)[i++] = (*str)[y++];
		(*str)[i] = '\0';
	}
	return (path);
}
