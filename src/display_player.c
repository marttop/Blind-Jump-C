/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player
*/

#include "rpg.h"

void display_hero(all_t *s_all)
{
    tp_animation(s_all);
    rect_hero(s_all);
    sfSprite_setPosition(s_all->s_player.shadow,
    (sfVector2f){s_all->s_player.hero_pos.x + 3,
    s_all->s_player.hero_pos.y + 26});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.shadow, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.hero, NULL);
}