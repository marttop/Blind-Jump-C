/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shoot2
*/

#include "rpg.h"

void shoot2(all_t *s_all)
{
    if (s_all->s_direction.up == 1) {
        s_all->s_player.shooting = 1, s_all->s_player.up = 1;
        s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
        s_all->s_player.ver = 1;
    } if (s_all->s_direction.down == 1) {
        s_all->s_player.shooting = 1, s_all->s_player.down = 1;
        s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
        s_all->s_player.ver = 1;
    }
}