##
## EPITECH PROJECT, 2023
## need4stek
## File description:
## Makefile
##

CC=gcc

CFLAGS = -Wall -Wextra -g

SRC =	$(wildcard src/*.c) \
		lib/str_to_word_array.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc	$(CFLAGS) $(SRC)	-o	$(NAME)

clean:
	rm	-rf	$(OBJ)

fclean: clean
	rm	-rf	$(NAME)

re:	fclean all
