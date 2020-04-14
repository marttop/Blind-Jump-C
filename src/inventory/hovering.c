/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hovering.c
*/

#include <inventory.h>

void hover_click(all_t *d, sfBool is_pressed, sfRenderWindow *w, t_slot *s)
{
    if (s->id != 100)
    sfRenderTexture_drawSprite(d->s_game.inventory.inv_tex,
        s->sprite_select, NULL);
    if (is_button_pressed(&d->s_game.event, sfMouseLeft)) {
        d->s_game.inventory.drag_info.slot = s;
        s->is_pressed = sfTrue;
        on_left_click(d, s, w);
    }
    else sfSprite_setColor(s->sprite_bg, (sfColor){255, 255, 255, 255});
}

void on_right_click(all_t *d, t_slot *s)
{
    if (is_button_released(&d->s_game.event, sfMouseRight)) {
        equip_weapon(d, s);
        unequip_weapon(d, s);
    }
}

void on_hover(void *data, struct slot *s, sfRenderWindow *w)
{
    static sfBool is_pressed = 0;
    all_t *d = (all_t *)data;
    hover_click(d, is_pressed, w, s);
    t_slot *tmp = d->s_game.inventory.drag_info.slot;
    if (tmp && tmp->has_item) {
        on_drop(data, s);
    }
    on_right_click(d, s);
    if (is_button_released(&d->s_game.event, sfMouseLeft)) {
        s->is_pressed = 0;
        tmp = NULL;
    }
}
