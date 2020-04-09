/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** shoot
*/

#include "rpg.h"

void shoot(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtKeyPressed
    && sfKeyboard_isKeyPressed(sfKeySpace) == 1 &&
    s_all->s_player.shooting == 0) {
        if (s_all->s_direction.left == 1) {
            s_all->s_player.shooting = 1;
            s_all->s_player.left = 1;
        } if (s_all->s_direction.right == 1) {
            s_all->s_player.shooting = 1;
            s_all->s_player.right = 1;
        } if (s_all->s_direction.up == 1) {
            s_all->s_player.shooting = 1;
            s_all->s_player.up = 1;
        } if (s_all->s_direction.down == 1) {
            s_all->s_player.shooting = 1;
            s_all->s_player.down = 1;
        }
    }
}

void shoot_direction(all_t *s_all)
{
    if (s_all->s_player.up == 1) {
        s_all->s_player.ver_pos.y -= 6;
        sfSprite_setPosition(s_all->s_player.ver_shoot,
        s_all->s_player.ver_pos);
    } if (s_all->s_player.down == 1) {
        s_all->s_player.ver_pos.y += 6;
        sfSprite_setPosition(s_all->s_player.ver_shoot,
        s_all->s_player.ver_pos);
    } if (s_all->s_player.left == 1) {
        s_all->s_player.hor_pos.x -= 6;
        sfSprite_setPosition(s_all->s_player.hor_shoot,
        s_all->s_player.hor_pos);
    } if (s_all->s_player.right == 1) {
        s_all->s_player.hor_pos.x += 6;
        sfSprite_setPosition(s_all->s_player.hor_shoot,
        s_all->s_player.hor_pos);
    }
}

void shooting_control(all_t *s_all)
{
    if (s_all->s_player.shoot_sec > 0.01) {
        if (s_all->s_player.shooting == 1 && s_all->s_player.range != 0) {
            shoot_direction(s_all);
            s_all->s_player.range -= 6;
        }
        if (s_all->s_player.range <= 0) {
            s_all->s_player.shooting = 0, s_all->s_player.range = 120;
            s_all->s_player.left = 0, s_all->s_player.right = 0;
            s_all->s_player.up = 0, s_all->s_player.down = 0;
            s_all->s_player.ver_pos = s_all->s_player.shoot_pos;
            s_all->s_player.hor_pos = s_all->s_player.shoot_pos;
            sfSprite_setPosition(s_all->s_player.hor_shoot,
            s_all->s_player.hor_pos);
            sfSprite_setPosition(s_all->s_player.ver_shoot,
            s_all->s_player.ver_pos);
        }
        sfClock_restart(s_all->s_player.shoot_clk);
    }
}