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
		src/display.c \
		src/game_loop.c \
		src/event_control.c \
		src/display_player.c \
		src/create_entities.c \
		src/player_movement.c \
		src/player_up_down_left_right.c \
		src/player_diagonal.c \
		src/hitbox_debug.c \
		src/hitbox_spawn.c \
		src/spawn_scene.c \
		src/display_effect.c \
		src/aim_direction.c \
		src/door_animation.c \
		src/camera.c \
		src/rect_hero.c \
		src/rect_hero2.c \
		src/rect_hero3.c \
		src/init/init_mobs.c \
		src/map.c \
		src/map2.c \
		src/mob_generator.c \
		src/vectors.c \
		src/chest_hitbox.c \
		src/shoot.c \
		src/mob_hitbox.c \
		src/map_generator.c \
		src/map_generator2.c \
		src/map_design.c \
		src/map_grass.c \
		src/tp_anim.c \
		src/destroy_mobs.c \
		src/inventory/inventory.c \
		src/inventory/slot_callbacks.c \
		src/inventory/inventory_input.c \
		src/inventory/list_helpers.c \
		src/inventory/tooltip.c \
		src/inventory/slot_utils.c \
		src/items/items_database.c \
		src/items/weapon.c \
		src/equipment/weapon_slot.c \
		src/equipment/equipment.c \
		src/init/init_player.c \
		src/init/init_infos.c \
		src/init/init_chests.c \
		src/init/init_movement.c \
		src/init/init_all.c \
		src/init/init_effect.c \
		src/init/init_explosions.c \
		src/teleporter.c \
		src/pathfinding/breadth_first_search.c \
		src/pathfinding/breadth_first_search_entity.c \
		src/pathfinding/dequeue.c \
		src/pathfinding/format_map.c \
		src/pathfinding/queue.c \
		src/pathfinding/mob_path.c \
		src/pathfinding/mob_movements.c \
		src/utils/get_next_line.c \
		src/utils/my_atoi.c \
		src/utils/my_putstr.c \
		src/utils/my_revstr.c \
		src/utils/my_strcat.c \
		src/utils/my_strcpy.c \
		src/utils/my_strdup.c \
		src/utils/my_strlen.c \
		src/utils/my_strnbr.c \
		src/utils/randomize.c \
		src/utils/write_file.c \
		src/utils/render_pos_center.c \

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
