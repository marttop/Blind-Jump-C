/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** options_menu
*/

#include "rpg.h"

void init_options_button(all_t *s_all)
{
    m_buttons_t *old = NULL;
    m_buttons_t *tmp = malloc(sizeof(m_buttons_t));
    tmp->sprite = sfSprite_create();
    tmp->button1 = sfTexture_createFromFile("sprites/buttons/quit1.png", NULL);
    tmp->button2 = sfTexture_createFromFile("sprites/buttons/quit2.png", NULL);
    sfSprite_setTexture(tmp->sprite, tmp->button1, sfTrue);
    sfSprite_setPosition(tmp->sprite, (sfVector2f){100, 940});
    tmp->position = (sfVector2f){100, 940};
    tmp->id = 5;
    tmp->next = old;
    old = tmp;
    s_all->s_options.buttons = old;
}

void init_options(all_t *s_all)
{
    s_all->s_options.bg_tx =
        sfTexture_createFromFile("sprites/background.png", NULL);
    s_all->s_options.bg = sfSprite_create();
    sfSprite_setTexture(s_all->s_options.bg, s_all->s_options.bg_tx, sfTrue);
    sfSprite_setScale(s_all->s_options.bg, (sfVector2f){10, 10});
    init_options_button(s_all);
    init_fps(s_all);
    init_volume1(s_all);
    init_volume2(s_all);
}

void draw_options(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_options.bg, NULL);
    dispay_buttons(s_all, s_all->s_options.buttons);
    draw_fps(s_all);
    draw_volume(s_all);
}

void draw_volume(all_t *s_all)
{
    adjust_volume(s_all);
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_options.s_volume.left, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    s_all->s_options.s_volume.bar1, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    s_all->s_options.s_volume.bar2, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_options.s_volume.right, NULL);
}