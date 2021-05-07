# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/08 23:43:06 by student           #+#    #+#              #
#    Updated: 2020/06/13 00:58:13 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
O_FILES = char_repeat.o format_analyze.o ft_printf.o ft_strlen.o print_bigx.o\
		  print_c.o print_d.o print_p.o print_s.o print_u.o print_x.o\
		  set_default.o in_array.o
CFLAGS = -Wall -Wextra -Werror
HEADER = ./includes/

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $@ $^
	ranlib $@

%.o: ./sources/%.c
	$(CC) -c $(CFLAGS) -I $(HEADER) -o $@ $<

bonus: all

clean:
	rm -f $(O_FILES) $(O_FILES_BON)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re _bonus
