/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_all
*/

#include "rpg.h"

void init_menu(all_t *s_all)
{
    create_sprite(&s_all->s_game.menu, &s_all->s_game.menu_tx,
        (sfVector2f){0, 0}, "sprites/menu.png");
    init_buttons(s_all);
    init_options(s_all);
    s_all->s_game.black = sfSprite_create();
    s_all->s_game.black_tx =
        sfTexture_createFromFile("sprites/black.png", NULL);
    sfSprite_setTexture(s_all->s_game.black, s_all->s_game.black_tx, sfTrue);
    sfSprite_setColor(s_all->s_game.black, (sfColor){0, 0, 0, 150});
}

void setup(all_t *s_all)
{
    sfVideoMode mode = {1920, 1080, 32};
    s_all->s_game.window = sfRenderWindow_create(mode, "Blind Jump",
        sfDefaultStyle, NULL);
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, 60);
    sfRenderWindow_setPosition(s_all->s_game.window, (sfVector2i){0, 0});
    s_all->s_game.scene = MENU;
    s_all->s_game.debug_mode = 0;
    s_all->s_game.display_inv = 0;
    s_all->s_game.pause = 0;
    s_all->s_game.fps = 60;
    s_all->s_game.volume = 1.0;
    s_all->s_mob = NULL;
    s_all->s_chest = NULL;
    s_all->s_game.font = sfFont_createFromFile("font/Cornerstone.ttf");
    s_all->s_game.monospaced = sfFont_createFromFile("font/joystix.ttf");
    init_view(s_all);
    randomize();
}

void init_all(all_t *s_all)
{
    setup(s_all);
    init_menu(s_all);
    init_clocks(s_all);
    init_hero(s_all);
    init_spawn(s_all);
    init_tp(s_all);
    init_effect(s_all);
    init_map(s_all);
    init_explosions(s_all);
    init_infos(s_all);
    init_inventory(s_all);
    init_custom(s_all);
    init_dead(s_all);
}