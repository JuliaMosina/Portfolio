# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 16:17:09 by alanora           #+#    #+#              #
#    Updated: 2021/01/02 16:18:36 by helen            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
LIBFT_GCC = -I $(LIBFT_PATH) $(LIBFT)
GNL_PATH = ./gnl
GNL = $(GNL_PATH)/gnl.a
GNL_GCC = -I $(GNL_PATH) $(GNL)

all: libft_create $(NAME)_create

libft_create:
	make -C $(LIBFT_PATH) all
	make -C $(GNL_PATH) all

$(NAME)_create:
	rm -f $(NAME)
	gcc sources/main.c sources/*/*.c -I ./includes $(LIBFT_GCC) $(GNL_GCC) -o $(NAME)

fclean:
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(GNL_PATH) fclean

re: fclean all

.PHONY:  all clean fclean re run diff
