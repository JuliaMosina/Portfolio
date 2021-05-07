/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helen <bmary@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:11:39 by helen             #+#    #+#             */
/*   Updated: 2020/07/26 13:12:26 by helen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		str_find(const char *str, char symbol)
{
	const char	*ptr;

	if (str == NULL)
		return (-1);
	ptr = str;
	while (*ptr != symbol && *ptr != '\0')
	{
		ptr++;
	}
	if (*ptr == symbol)
		return (ptr - str);
	else
		return (-1);
}

void	str_copy(const char *source, char *dest, int count)
{
	if (source == NULL || dest == NULL)
		return ;
	while (count > 0)
	{
		*dest = *source;
		source++;
		dest++;
		count--;
	}
}

int		str_len(char *string)
{
	int		i;

	i = 0;
	while (*string != '\0')
	{
		i++;
		string++;
	}
	return (i);
}

char	*malloc_and_terminate(int size)
{
	char	*buffer;

	if (size == 0)
		return (NULL);
	if ((buffer = (char *)malloc(sizeof(char) * (size + 1))) != NULL)
		buffer[0] = '\0';
	return (buffer);
}

int		clear_buffers(char **static_buffer, char *from_file_buffer)
{
	free(from_file_buffer);
	free(*static_buffer);
	*static_buffer = NULL;
	return (-1);
}
