##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## makefile
##

NAME	=	my_rpg

CC	=	gcc

SRC	=	src/main.c \
		src/clock.c \
		src/init_all.c \
		src/display.c \
		src/game_loop.c \
		src/event_control.c \
		utils/get_next_line.c \
		utils/my_atoi.c \
		utils/my_putstr.c \
		utils/my_revstr.c \
		utils/my_strcat.c \
		utils/my_strcpy.c \
		utils/my_strdup.c \
		utils/my_strlen.c \
		utils/my_strnbr.c \
		utils/randomize.c \
		utils/write_file.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra
CFLAGS	+=	-I./include -g3
FFLAGS	+=	-l csfml-system
FFLAGS	+=	-l csfml-graphics
FFLAGS	+=	-l csfml-audio
FFLAGS	+=	-l csfml-window
FFLAGS  +=	-lm

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(FFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
