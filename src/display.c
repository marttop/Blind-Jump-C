/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "rpg.h"

void display(all_t *s_all)
{
    sfRenderWindow_clear(s_all->s_game.window, sfBlack);
    if (s_all->s_game.scene == SPAWN) {
        sfRenderWindow_clear(s_all->s_game.window, (sfColor){19, 45, 51, 255});
        display_spawn_under(s_all);
        display_hero(s_all);
        display_spawn_over(s_all);
        move_camera(s_all);
    }
    sfRenderWindow_display(s_all->s_game.window);
}