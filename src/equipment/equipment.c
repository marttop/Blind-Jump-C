/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** equipment.c
*/

#include "rpg.h"
#include "equipment.h"

void init_equipment(all_t *s_all)
{
    t_equipment *e = &s_all->s_game.equipment;
    e->render_tex = sfRenderTexture_create(64, 64, 0);
    e->render_sprite = sfSprite_create();
    sfSprite_setPosition(e->render_sprite, (sfVector2f){600, 910});
    sfSprite_setTexture(e->render_sprite,
        sfRenderTexture_getTexture(e->render_tex), 1);
    init_weapon_slot(s_all);
}

void draw_equipment(all_t *s_all)
{
    t_equipment *e = &s_all->s_game.equipment;
    sfRenderTexture_clear(e->render_tex, sfRed);
    draw_weapon_slot(s_all);
    sfRenderTexture_display(e->render_tex);
    sfRenderWindow_drawSprite(s_all->s_game.window, e->render_sprite, NULL);
}