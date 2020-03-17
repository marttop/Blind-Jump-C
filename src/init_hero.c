/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_hero
*/

#include "rpg.h"

void init_hero(all_t *s_all)
{
    s_all->s_player.hero_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_player.hero, &s_all->s_player.hero_tx,
        s_all->s_player.hero_pos, "sprites/round.png");
    s_all->s_player.hero_speed = 20;
    s_all->s_player.hero_clock = sfClock_create();
}