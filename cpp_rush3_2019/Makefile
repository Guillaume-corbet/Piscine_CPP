##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## program
##

SRC	=	main.cpp		\
		ncurses/Terminal.cpp	\
		data/Data.cpp	\
		data/Ram.cpp	\
		data/Monitor.cpp	\
		data/FileManip.cpp	\
		data/Processor.cpp	\
		ncurses/Ncurses.cpp	\
		sfml/sfml.cpp	\
		data/Network.cpp

NAME	=	MyGKrellm

FLAGS	=	-W -Wall -Werror -Wextra 

all:	$(NAME) 

$(NAME):
		g++ -o $(NAME) $(SRC) -lncurses -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

valgrind:
		g++ -o $(NAME) $(SRC) -g3 -lncurses

warning:
		g++ -o $(NAME) $(SRC) $(FLAGS) -g3 -lncurses

optimize:
		g++ -o $(NAME) $(SRC) -O4 -lncurses

clean:
		rm -f $(NAME)

fclean:
		rm -f $(NAME)
		rm -f *~
		rm -f *#

re:		fclean all
