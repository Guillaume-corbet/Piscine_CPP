##
## EPITECH PROJECT, 2019
## lib/my/
## File description:
## Makefile
##

SRC		=		string.c	\
				assign.c	\
				append.c	\
				at.c		\
				clear.c		\
				size.c		\
				compare.c	\
				copy.c		\
				c_str.c		\
				empty.c		\
				find.c		\
				insert.c	\
				to_int.c	\
				split.c		\
				print.c

OBJ		=		$(SRC:.c=.o)

NAME	=		libstring.a

all:	$(NAME) clean

$(NAME):	$(OBJ)
			ar rc $(NAME) *.o

clean:
		rm -f $(OBJ)

fclean:
		rm -f $(NAME)
		rm -f *.o
		rm -f *.a

re:	fclean all

auteur:
		echo $(USER) > Guillaume
