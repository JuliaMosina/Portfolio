HF = *.h
SF = *.c
OPT = -Wall -Wextra -Werror
NAME = gnl.a
OBJ = *.o
CC = gcc

all: $(NAME)

$(NAME):
		gcc -c $(SF) -I$(HF) $(OPT) -D BUFFER_SIZE=32
		ar rc gnl.a $(OBJ)
		ranlib gnl.a

clean:
		@/bin/rm -rf *.o

fclean: clean
		@/bin/rm -rf $(NAME)

re:		fclean all
