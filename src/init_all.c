/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_all
*/

#include "rpg.h"

void init_view(all_t *s_all)
{
    s_all->s_game.camera =
        sfView_copy(sfRenderWindow_getView(s_all->s_game.window));
    sfView_zoom(s_all->s_game.camera, 0.4);
    sfView_setCenter(s_all->s_game.camera,
    (sfVector2f){sfMouse_getPositionRenderWindow(s_all->s_game.window).x + 10,
    sfMouse_getPositionRenderWindow(s_all->s_game.window).y});
    sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
}

void setup(all_t *s_all)
{
    sfVideoMode mode = {1920, 1080, 32};
    s_all->s_game.window = sfRenderWindow_create(mode, "MY_RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, 60);
    sfRenderWindow_setPosition(s_all->s_game.window, (sfVector2i){0, 0});
    s_all->s_game.scene = SPAWN;
    s_all->s_game.debug_mode = 0;
    init_view(s_all);
    randomize();
}

void init_all(all_t *s_all)
{
    setup(s_all);
    init_inventory(s_all);
    init_clocks(s_all);
    init_hero(s_all);
    init_spawn(s_all);
}