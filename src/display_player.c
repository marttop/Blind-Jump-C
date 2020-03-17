/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player
*/

#include "rpg.h"

void display_hero(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.hero, NULL);
}