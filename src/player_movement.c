/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_movement
*/

#include "rpg.h"

void get_movement(all_t *s_all)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == 1)
        s_all->s_movement.up = 1;
    else
        s_all->s_movement.up = 0;

    if (sfKeyboard_isKeyPressed(sfKeyDown) == 1)
        s_all->s_movement.down = 1;
    else
        s_all->s_movement.down = 0;

    if (sfKeyboard_isKeyPressed(sfKeyLeft) == 1)
        s_all->s_movement.left = 1;
    else
        s_all->s_movement.left = 0;

    if (sfKeyboard_isKeyPressed(sfKeyRight) == 1)
        s_all->s_movement.right = 1;
    else
        s_all->s_movement.right = 0;
}

void player_movement(all_t *s_all)
{
    if (s_all->s_game.scene == 0 || check_borders(s_all) == 1
    || check_middle_wall(s_all) == 1 || check_ship(s_all) == 1
    || s_all->s_player.tp == 1)
        return;

    if ((s_all->s_movement.left == 0 && s_all->s_movement.right == 0)
    || (s_all->s_movement.left == 1 && s_all->s_movement.right == 1))
        movement_up_down(s_all);

    if ((s_all->s_movement.up == 0 && s_all->s_movement.down == 0)
    || (s_all->s_movement.up == 1 && s_all->s_movement.down == 1))
        movement_left_right(s_all);

    movement_diagonal_left(s_all);
    movement_diagonal_right(s_all);

    set_position_debug(s_all->s_player.debug, s_all->s_player.hero_pos);
}