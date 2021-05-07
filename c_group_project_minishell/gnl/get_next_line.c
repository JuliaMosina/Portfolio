/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helen <bmary@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:09:48 by helen             #+#    #+#             */
/*   Updated: 2020/07/26 13:10:39 by helen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_move(char **source)
{
	char	*result_string;
	int		len;

	len = str_len(*source);
	result_string = (char *)malloc(sizeof(char) * (len + 1));
	str_copy(*source, result_string, len);
	if (result_string != NULL)
		result_string[len] = '\0';
	free(*source);
	*source = NULL;
	return (result_string);
}

char	*str_substr_alloc(const char *source, int len)
{
	char	*substring;

	substring = (char *)malloc(sizeof(char) * (len + 1));
	str_copy(source, substring, len);
	if (substring != NULL)
		substring[len] = '\0';
	return (substring);
}

char	*cut_line(char **source, int position)
{
	char	*tail_string;
	char	*tail_pointer;
	char	*head_string;

	head_string = str_substr_alloc(*source, position);
	tail_pointer = (*source) + position + 1;
	if (*tail_pointer == '\0')
	{
		free(*source);
		*source = NULL;
		return (head_string);
	}
	tail_string = str_substr_alloc(tail_pointer, str_len(tail_pointer));
	free(*source);
	*source = tail_string;
	return (head_string);
}

char	*str_concat(char *str1, char *str2)
{
	int		new_len;
	char	*return_str;
	int		str1_len;

	str1_len = str_len(str1);
	new_len = str1_len + str_len(str2);
	return_str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (return_str == NULL)
		return (NULL);
	str_copy(str1, return_str, str1_len);
	str_copy(str2, return_str + str1_len, str_len(str2));
	return_str[new_len] = '\0';
	free(str1);
	free(str2);
	return (return_str);
}

int		get_next_line(int fd, char **line)
{
	static char	*s_buf;
	char		*f_buf;
	int			temp_len;
	int			new_line_pos;

	if (line != NULL && s_buf == NULL)
		s_buf = malloc_and_terminate(BUFFER_SIZE);
	while (line != NULL && s_buf != NULL)
	{
		if (*s_buf != '\0' && (new_line_pos = str_find(s_buf, '\n')) != -1)
			return ((*line = cut_line(&s_buf, new_line_pos)) != NULL ? 1 : -1);
		if ((f_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))) == NULL)
			return (clear_buffers(&s_buf, f_buf));
		if ((temp_len = read(fd, f_buf, BUFFER_SIZE)) >= 0 && f_buf != NULL)
			f_buf[temp_len] = '\0';
		if (temp_len == -1)
			return (clear_buffers(&s_buf, f_buf));
		if (temp_len == 0)
		{
			free(f_buf);
			return ((*line = str_move(&s_buf)) != NULL ? 0 : -1);
		}
		s_buf = str_concat(s_buf, f_buf);
	}
	return (-1);
}
