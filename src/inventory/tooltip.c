/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** tooltip.c
*/

#include "rpg.h"

void init_tooltip(all_t *s_all)
{
    t_dragtip *tip = &s_all->s_game.inventory.dragtip;
    tip->item_sprite = sfSprite_create();
    tip->render_tex = sfRenderTexture_create(64, 64, 0);
    tip->render_sprite = sfSprite_create();
    sfSprite_setTexture(tip->render_sprite,
    sfRenderTexture_getTexture(tip->render_tex), 1);
}

void draw_tooltip(all_t *s_all)
{
    t_dragtip *tip = &s_all->s_game.inventory.dragtip;
    sfRenderTexture_clear(tip->render_tex, (sfColor){100, 100, 100, 100});
    sfRenderTexture_display(tip->render_tex);
    sfRenderWindow_drawSprite(s_all->s_game.window, tip->render_sprite, NULL);
}