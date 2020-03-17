/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** clock
*/

#include "rpg.h"

void init_clocks(all_t *s_all)
{
    s_all->s_game.clock = sfClock_create();
}

void player_clocks(all_t *s_all)
{
    s_all->s_player.hero_time =
        sfClock_getElapsedTime(s_all->s_player.hero_clock);
    s_all->s_player.hero_seconds =
        s_all->s_player.hero_time.microseconds / 1000000.0;
}

void game_clocks(all_t *s_all)
{
    s_all->s_game.time = sfClock_getElapsedTime(s_all->s_game.clock);
    s_all->s_game.seconds = s_all->s_game.time.microseconds / 1000000.0;
    player_clocks(s_all);
}