##
## EPITECH PROJECT, 2021
## palindrome
## File description:
## Makefile
##

SRC =	main.c \
		random_float.c

OBJ = $(SRC:.c=.o)

NAME = pong

CFLAGS += -Werror -Wextra -I./include -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system\
			-lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lm -g3

$(NAME): $(OBJ)
	cc -o $(NAME) $(OBJ) $(CFLAGS)

all:     $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
