/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** cinematic
*/

#include "rpg.h"

void cinematic1(all_t *s_all)
{
    if (s_all->s_cine.seconds < 0.01) return;
    if (s_all->s_cine.script == 0 && s_all->s_cine.tuto == 1) {
        s_all->s_cine.move = 2;
        s_all->s_npc.talk = 1, s_all->s_game.chat = 1;
    }
    sfClock_restart(s_all->s_cine.clock);
}