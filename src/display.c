/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "rpg.h"

void display(all_t *s_all)
{
    if (s_all->s_game.scene == 0) {
        sfRenderWindow_clear(s_all->s_game.window, sfBlack);
        display_hero(s_all);
    }
    sfRenderWindow_display(s_all->s_game.window);
}