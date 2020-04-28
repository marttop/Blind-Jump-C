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
        sfSprite_setPosition(s_all->s_dead.dead, s_all->s_player.hero_pos);
        s_all->s_game.scene = GAME_OVER;
        sfSprite_setColor(s_all->s_dead.dead, s_all->s_custom.p_color);
    }
}

void display_game_over(all_t *s_all)
{
    if (s_all->s_game.scene == GAME_OVER) {
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_infos.game_over, NULL);
    }
}