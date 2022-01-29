##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## make test
##

SRC	=	./menger.c		\
		./main.c

NAME	=	menger

FLAGS	=	-std=gnu11 -Wall -Wextra

all:	$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC)

valgrind:
		gcc -o $(NAME) $(SRC) -g3

warning:
		gcc -o $(NAME) $(SRC) $(FLAGS) -g3

optimize:
		gcc -o $(NAME) $(SRC) -O4

clean:
		rm -f $(NAME)

fclean:
		rm -f $(NAME)
		rm -f *~
		rm -f *#

re:		fclean all
