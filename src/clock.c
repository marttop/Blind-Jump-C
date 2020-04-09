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
    s_all->s_player.rect_time =
        sfClock_getElapsedTime(s_all->s_player.rect_clock);
    s_all->s_player.rect_seconds =
        s_all->s_player.rect_time.microseconds / 1000000.0;
    s_all->s_player.refresh_tm =
        sfClock_getElapsedTime(s_all->s_player.refresh_clk);
    s_all->s_player.refresh_sec =
        s_all->s_player.refresh_tm.microseconds / 1000000.0;
    s_all->s_player.shoot_tm =
        sfClock_getElapsedTime(s_all->s_player.shoot_clk);
    s_all->s_player.shoot_sec =
        s_all->s_player.shoot_tm.microseconds / 1000000.0;
}

void mob_clocks(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    while (temp != NULL) {
        temp->time = sfClock_getElapsedTime(temp->clock);
        temp->seconds = temp->time.microseconds / 1000000.0;
        temp->refresh_tm = sfClock_getElapsedTime(temp->refresh_clk);
        temp->refresh_sec = temp->refresh_tm.microseconds / 1000000.0;
        temp->rect_time = sfClock_getElapsedTime(temp->rect_clock);
        temp->rect_seconds = temp->rect_time.microseconds / 1000000.0;
        temp = temp->next;
    }
}

void game_clocks(all_t *s_all)
{
    s_all->s_game.time = sfClock_getElapsedTime(s_all->s_game.clock);
    s_all->s_game.seconds = s_all->s_game.time.microseconds / 1000000.0;
    s_all->s_spawn.door_time =
        sfClock_getElapsedTime(s_all->s_spawn.door_clock);
    s_all->s_spawn.door_seconds =
        s_all->s_spawn.door_time.microseconds / 1000000.0;
    s_all->s_tp.tp_time =
        sfClock_getElapsedTime(s_all->s_tp.tp_clock);
    s_all->s_tp.tp_seconds =
        s_all->s_tp.tp_time.microseconds / 1000000.0;
    player_clocks(s_all);
    mob_clocks(s_all);
    sfClock_restart(s_all->s_game.clock);
}