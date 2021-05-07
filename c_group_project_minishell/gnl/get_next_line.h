/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helen <bmary@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 13:13:03 by helen             #+#    #+#             */
/*   Updated: 2020/07/26 13:15:23 by helen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65534
# endif
# if BUFFER_SIZE < 1
#  error "BUFFER_SIZE is incorrect"
# endif
# if BUFFER_SIZE > 65534
#  error "BUFFER_SIZE is incorrect"
# endif

int		str_find(const char *str, char symbol);
void	str_copy(const char *source, char *dest, int count);
int		str_len(char *string);
int		get_next_line(int fd, char **line);
char	*malloc_and_terminate(int size);
int		clear_buffers(char **static_buffer, char *from_file_buffer);

#endif
