/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "rpg.h"

void display(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN) {
        sfRenderWindow_clear(s_all->s_game.window, (sfColor){19, 45, 51, 255});
        sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
        display_spawn_under(s_all);
        display_hero(s_all);
        display_spawn_over(s_all);
        move_camera(s_all);
        sfRenderWindow_setView(s_all->s_game.window,
        sfRenderWindow_getDefaultView(s_all->s_game.window));
        draw_inventory(s_all);
        if (s_all->s_game.inventory.drag_info.slot &&
            s_all->s_game.inventory.drag_info.slot->is_dragging)
        draw_tooltip(s_all);
    }
    sfRenderWindow_display(s_all->s_game.window);
}