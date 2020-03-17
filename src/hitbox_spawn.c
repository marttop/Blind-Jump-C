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
    ((s_all->s_player.hero_pos.x >= 1045 && s_all->s_movement.right == 1)
    || (s_all->s_player.hero_pos.x <= 860 && s_all->s_movement.left == 1)
    || (s_all->s_player.hero_pos.y >= 795 && s_all->s_movement.down == 1)
    || (s_all->s_player.hero_pos.y <= 270 && s_all->s_movement.up == 1)))
        return (1);
    return (0);
}

int check_middle_wall(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN && ((s_all->s_player.hero_pos.x <= 928
    && s_all->s_player.hero_pos.y <= 587 && s_all->s_player.hero_pos.y >= 575
    && s_all->s_movement.up == 1) || (s_all->s_player.hero_pos.x >= 968
    && s_all->s_player.hero_pos.y <= 587 && s_all->s_player.hero_pos.y >= 575
    && s_all->s_movement.up == 1) || (s_all->s_player.hero_pos.x <= 928
    && s_all->s_player.hero_pos.y >= 570 && s_all->s_player.hero_pos.y <= 582
    && s_all->s_movement.down == 1) || (s_all->s_player.hero_pos.x >= 968
    && s_all->s_player.hero_pos.y >= 570 && s_all->s_player.hero_pos.y <= 582
    && s_all->s_movement.down == 1)))
        return (1);
    return (0);
}