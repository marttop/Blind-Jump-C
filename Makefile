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
		src/display_player.c \
		src/create_entities.c \
		src/player_movement.c \
		src/player_up_down_left_right.c \
		src/init_player.c \
		src/hitbox_debug.c \
		src/hitbox_spawn.c \
		src/init_movement.c \
		src/spawn_scene.c \
		src/aim_direction.c \
		src/camera.c \
		src/rect_hero.c \
		src/rect_hero2.c \
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
		utils/render_pos_center.c \
		src/inventory/inventory.c \
		src/inventory/slot_callbacks.c \
		src/inventory/inventory_input.c \
		src/inventory/list_helpers.c \
		src/items/items_database.c \
		src/items/weapon.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -Wno-unused-parameter
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
