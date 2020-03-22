/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_up_down_left_right
*/

#include "rpg.h"

void movement_up_down(all_t *s_all)
{
    if (s_all->s_player.hero_seconds >= 0.01 && s_all->s_movement.up == 1
    && s_all->s_movement.down != 1) {

        s_all->s_player.hero_pos.y -= s_all->s_player.hero_speed;
        sfSprite_setPosition(s_all->s_player.hero,
            s_all->s_player.hero_pos);
        sfClock_restart(s_all->s_player.hero_clock);
    }

    if (s_all->s_player.hero_seconds >= 0.01 && s_all->s_movement.down == 1
    && s_all->s_movement.up != 1) {

        s_all->s_player.hero_pos.y += s_all->s_player.hero_speed;
        sfSprite_setPosition(s_all->s_player.hero,
            s_all->s_player.hero_pos);
        sfClock_restart(s_all->s_player.hero_clock);
    }
}

void movement_left_right(all_t *s_all)
{
    if (s_all->s_player.hero_seconds >= 0.01 && s_all->s_movement.left == 1
    && s_all->s_movement.right != 1) {

        s_all->s_player.hero_pos.x -= s_all->s_player.hero_speed;
        sfSprite_setPosition(s_all->s_player.hero,
            s_all->s_player.hero_pos);
        sfClock_restart(s_all->s_player.hero_clock);
    }

    if (s_all->s_player.hero_seconds >= 0.01
        && s_all->s_movement.right == 1 && s_all->s_movement.left != 1) {

        s_all->s_player.hero_pos.x += s_all->s_player.hero_speed;
        sfSprite_setPosition(s_all->s_player.hero,
            s_all->s_player.hero_pos);
        sfClock_restart(s_all->s_player.hero_clock);
    }
}