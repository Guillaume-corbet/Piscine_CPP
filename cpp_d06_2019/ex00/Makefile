##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## program
##

SRC	=	cat.cpp

NAME	=	my_cat

FLAGS	=	-W -Wall -Werror -Wextra

INC	=	-I include

all:	$(NAME)

$(NAME):
		g++ -o $(NAME) $(SRC) $(INC)

valgrind:
		g++ -o $(NAME) $(SRC) $(INC) -g3

warning:
		g++ -o $(NAME) $(SRC) $(FLAGS) $(INC) -g3

optimize:
		g++ -o $(NAME) $(SRC) $(INC) -O4

clean:
		rm -f $(NAME)

fclean:
		rm -f $(NAME)
		rm -f *~
		rm -f *#

re:		fclean all
