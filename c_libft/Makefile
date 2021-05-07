# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/11 23:01:55 by student           #+#    #+#              #
#    Updated: 2020/05/18 00:43:59 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
O_FILES = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
	ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memccpy.o ft_memchr.o \
	ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o \
	ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o \
	ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o \
	ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o \
	ft_toupper.o ft_strndup.o
O_FILES_BON = ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o \
	ft_lstlast.o ft_lstnew.o ft_lstsize.o
CFLAGS = -Wall -Wextra -Werror
HEADER = ./

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $@ $^
	ranlib $@

%.o: %.c
	$(CC) -c $(CFLAGS) -I $(HEADER) -o $@ $<

bonus: $(O_FILES) $(O_FILES_BON)
	ar rc $(NAME) $^
	ranlib $(NAME)

clean:
	rm -f $(O_FILES) $(O_FILES_BON)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
