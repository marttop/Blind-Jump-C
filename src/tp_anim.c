/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** tp_anim
*/

#include "rpg.h"

void tp_animation3(all_t *s_all)
{
    if (s_all->s_tp.width >= 20 && s_all->s_tp.anim == 1)
        s_all->s_tp.anim = 2;
    if (s_all->s_tp.anim == 2 && s_all->s_tp.width > 0) {
        s_all->s_tp.width -= 1;
        sfRectangleShape_setOrigin(s_all->s_tp.beam,
            (sfVector2f){s_all->s_tp.width / 2, s_all->s_tp.height});
    }
    sfRectangleShape_setSize(s_all->s_tp.beam,
        (sfVector2f){s_all->s_tp.width, s_all->s_tp.height});
}

void tp_animation2(all_t *s_all)
{
    if (s_all->s_player.tp == 1 && s_all->s_tp.tp_seconds >= 0.01) {
        if (s_all->s_tp.anim == 0 && s_all->s_tp.alpha < 240) {
            s_all->s_tp.alpha += 10;
            s_all->s_tp.height += 10;
            sfRectangleShape_setOrigin(s_all->s_tp.beam,
                (sfVector2f){1, s_all->s_tp.height});
            sfRectangleShape_setFillColor(s_all->s_tp.beam,
                (sfColor){120, 255, 242, s_all->s_tp.alpha});
        } if (s_all->s_tp.anim == 0 && s_all->s_tp.alpha >= 240) {
            s_all->s_tp.anim = 1;
            sfRectangleShape_setFillColor(s_all->s_tp.beam,
                (sfColor){120, 255, 242, 255});
        }
        if (s_all->s_tp.anim == 1 && s_all->s_tp.width < 20) {
            s_all->s_tp.width += 2;
            sfRectangleShape_setOrigin(s_all->s_tp.beam,
                (sfVector2f){s_all->s_tp.width / 2, s_all->s_tp.height});
        }
        tp_animation3(s_all);
    }
}

void tp_animation(all_t *s_all)
{
    if (hitbox_tp(s_all) == 1 && s_all->s_player.tp == 0) {
        s_all->s_player.tp = 1;
        s_all->s_player.hero_rect.left = 406;
        s_all->s_player.hero_rect.top = 109;
        s_all->s_player.hero_rect.height = 31;
        sfSprite_setTextureRect(s_all->s_player.hero,
            s_all->s_player.hero_rect);
        s_all->s_player.hero_pos = (sfVector2f){s_all->s_tp.tp_pos.x + 6,
            s_all->s_tp.tp_pos.y - 17};
        sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        sfRectangleShape_setPosition(s_all->s_player.debug,
            s_all->s_player.hero_pos);
    }
    tp_animation2(s_all);
}