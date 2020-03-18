/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player
*/

#include "rpg.h"

void display_hero(all_t *s_all)
{
    rect_hero(s_all);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.hero, NULL);
    sfSprite_setPosition(s_all->s_player.shadow,
    (sfVector2f){s_all->s_player.hero_pos.x + 1,
    s_all->s_player.hero_pos.y + 25});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.shadow, NULL);
    if (s_all->s_game.debug_mode == 1) {
        display_hitbox_debug(s_all, s_all->s_player.debug,
            s_all->s_player.hero);
    }
}