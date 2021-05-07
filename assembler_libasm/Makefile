# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <alanora@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/03 03:13:11 by student           #+#    #+#              #
#    Updated: 2020/11/03 03:44:06 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
O_FILES = ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o ft_strdup.o
HEADER = ./includes
ASM = nasm
ASM_FLAGS = -f macho64

all: $(NAME)

$(NAME): $(O_FILES)
	ar rc $@ $^
	ranlib $@

%.o: ./sources/%.s
	$(ASM) $(ASM_FLAGS) -I $(HEADER) -o $@ $<

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
