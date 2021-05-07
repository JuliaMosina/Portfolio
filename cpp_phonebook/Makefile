# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanora <alanora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 20:11:09 by alanora           #+#    #+#              #
#    Updated: 2021/03/10 20:22:36 by alanora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
OBJS = phonebook.o contact.o main.o
FLAGS = -Wall -Wextra -Werror -I ./

all: $(NAME)

$(NAME): $(OBJS)
	clang++ $(FLAGS) -o $(NAME) $(OBJS)

%.o: ./%.cpp
	clang++ -c $(FLAGS) -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:  all clean fclean re