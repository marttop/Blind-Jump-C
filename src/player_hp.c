/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** player_hp
*/

#include "rpg.h"

void loosing_hp(all_t *s_all)
{
    s_all->s_infos.is_hit = 1;
    sfClock_restart(s_all->s_infos.clock);
    s_all->s_infos.current_hp -= 20;
    if (s_all->s_infos.str_hp != NULL) free(s_all->s_infos.str_hp);
    s_all->s_infos.str_hp = malloc(20);
    s_all->s_infos.str_hp[0] = '\0';
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.current_hp));
    my_strcat(s_all->s_infos.str_hp, "/");
    my_strcat(s_all->s_infos.str_hp, strnbr(s_all->s_infos.max_hp));
    sfText_setString(s_all->s_infos.hp_txt, s_all->s_infos.str_hp);
    sfRectangleShape_setSize(s_all->s_infos.hp,
    (sfVector2f){250 / s_all->s_infos.max_hp * s_all->s_infos.current_hp, 20});
}

void player_immunity(all_t *s_all)
{
    sfColor color = sfSprite_getColor(s_all->s_player.hero);
    if (s_all->s_infos.seconds >= 1 && s_all->s_infos.is_hit == 1) {
        s_all->s_infos.is_hit = 0;
        color.a = 255;
        sfSprite_setColor(s_all->s_player.hero, color);
    }
    else if (s_all->s_infos.is_hit == 1 && s_all->s_infos.hit_sec > 0.01) {
        if (s_all->s_infos.is_color == 0) {
            color.a -= 20;
            sfSprite_setColor(s_all->s_player.hero, color);
        }
        else if (s_all->s_infos.is_color == 1) {
            color.a += 20;
            sfSprite_setColor(s_all->s_player.hero, color);
        }
        if (color.a < 100) s_all->s_infos.is_color = 1;
        if (color.a >= 255) s_all->s_infos.is_color = 0;
        sfClock_restart(s_all->s_infos.hit_clk);
    }
}