/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** camera
*/

#include "rpg.h"

void move_camera(all_t *s_all)
{
    sfView_setCenter(s_all->s_game.camera, s_all->s_player.hero_pos);
    sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
}