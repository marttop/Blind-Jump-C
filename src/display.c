/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "rpg.h"

void display_spawn(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN) {
        sfRenderWindow_clear(s_all->s_game.window, (sfColor){12, 37, 41, 255});
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
}

void display_map(all_t *s_all)
{
    if (s_all->s_game.scene == MAP) {
        sfRenderWindow_clear(s_all->s_game.window, sfBlack);
        sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
        sfSprite_setPosition(s_all->s_map.background,
            s_all->s_effect.vignette_pos);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_map.background, NULL);
        display_tiles(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_tp.tp, NULL);
        display_chests(s_all);
        display_mobs(s_all);
        display_hero(s_all);
        display_explosions(s_all);
    }
}

void display_hud_anim(all_t *s_all)
{
    display_debug(s_all);
    move_camera(s_all);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_tp.beam, NULL);
    sfRenderWindow_setView(s_all->s_game.window,
        sfRenderWindow_getDefaultView(s_all->s_game.window));
    draw_inventory(s_all);
}

void display(all_t *s_all)
{
    display_spawn(s_all);
    display_map(s_all);
    display_hud_anim(s_all);
    sfRenderWindow_display(s_all->s_game.window);
}