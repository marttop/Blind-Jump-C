/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_all
*/

#include "rpg.h"

void setup(all_t *s_all)
{
    sfVideoMode mode = {1920, 1080, 32};
    s_all->s_game.window = sfRenderWindow_create(mode, "MY_RPG",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, 60);
    sfRenderWindow_setPosition(s_all->s_game.window, (sfVector2i){0, 0});
    s_all->s_game.scene = SPAWN;
    s_all->s_game.debug_mode = 0;
    s_all->s_game.display_inv = 0;
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
    init_tp(s_all);
    init_effect(s_all);
    init_map(s_all);
    init_mobs(s_all);
}