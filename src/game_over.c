/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** game_over
*/

#include "rpg.h"

void game_over_check(all_t *s_all)
{
    if (s_all->s_infos.current_hp <= 0) {
        s_all->s_game.scene = GAME_OVER;
    }
}

void display_game_over(all_t *s_all)
{
    if (s_all->s_game.scene == GAME_OVER) {
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_infos.game_over, NULL);
    }
}