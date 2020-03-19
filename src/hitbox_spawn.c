/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** hitbox_spawn
*/

#include "rpg.h"

int check_borders(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN &&
    ((s_all->s_player.hero_pos.x >= 1040 && s_all->s_movement.right == 1)
    || (s_all->s_player.hero_pos.x <= 860 && s_all->s_movement.left == 1)
    || (s_all->s_player.hero_pos.y >= 795 && s_all->s_movement.down == 1)
    || (s_all->s_player.hero_pos.y <= 270 && s_all->s_movement.up == 1)))
        return (1);
    return (0);
}

int check_middle_wall(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN && ((s_all->s_player.hero_pos.x <= 920
    && s_all->s_player.hero_pos.y <= 587 && s_all->s_player.hero_pos.y >= 575
    && s_all->s_movement.up == 1) || (s_all->s_player.hero_pos.x >= 967
    && s_all->s_player.hero_pos.y <= 587 && s_all->s_player.hero_pos.y >= 575
    && s_all->s_movement.up == 1) || (s_all->s_player.hero_pos.x <= 920
    && s_all->s_player.hero_pos.y >= 570 && s_all->s_player.hero_pos.y <= 582
    && s_all->s_movement.down == 1) || (s_all->s_player.hero_pos.x >= 967
    && s_all->s_player.hero_pos.y >= 570 && s_all->s_player.hero_pos.y <= 582
    && s_all->s_movement.down == 1) || (s_all->s_player.hero_pos.x <= 925
    && s_all->s_player.hero_pos.y <= 582 && s_all->s_player.hero_pos.y >= 575
    && s_all->s_movement.left == 1) || (s_all->s_player.hero_pos.x >= 960
    && s_all->s_player.hero_pos.y <= 582 && s_all->s_player.hero_pos.y >= 575
    && s_all->s_movement.right == 1)))
        return (1);
    return (0);
}

int check_ship(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN && ((s_all->s_player.hero_pos.y <= 685
    && s_all->s_player.hero_pos.x <= 990 && s_all->s_player.hero_pos.x >= 938
    && s_all->s_movement.up == 1 && s_all->s_player.hero_pos.y >= 660)
    || (s_all->s_player.hero_pos.y <= 675 && s_all->s_player.hero_pos.x <= 990
    && s_all->s_player.hero_pos.x >= 938 && s_all->s_movement.down == 1
    && s_all->s_player.hero_pos.y >= 650) || (s_all->s_player.hero_pos.y <= 680
    && s_all->s_player.hero_pos.x <= 990 && s_all->s_player.hero_pos.x >= 935
    && s_all->s_movement.right == 1 && s_all->s_player.hero_pos.y >= 655) ||
    (s_all->s_player.hero_pos.y <= 680 && s_all->s_player.hero_pos.x <= 995
    && s_all->s_player.hero_pos.x >= 940 && s_all->s_movement.left == 1
    && s_all->s_player.hero_pos.y >= 655)))
        return (1);
    return (0);
}