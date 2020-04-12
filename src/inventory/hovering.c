/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** hovering.c
*/

#include <inventory.h>

void hover_click(all_t *d, sfBool is_pressed, sfRenderWindow *w, t_slot *s)
{
    sfRenderTexture_drawSprite(d->s_game.inventory.inv_tex,
        s->sprite_select, NULL);
    if (is_button_pressed(&d->s_game.event, sfMouseLeft)) {
        d->s_game.inventory.drag_info.slot = s;
        is_pressed = sfTrue;
        on_click(d, s, w);
    }
    else sfSprite_setColor(s->sprite_bg, (sfColor){255, 255, 255, 255});
    if (is_pressed && d->s_game.event.mouseMove.type == sfEvtMouseMoved) {
        if (d->s_game.inventory.drag_info.slot->has_item) {
            on_drag(d, d->s_game.inventory.drag_info.slot, w);
        }
    }
    else s->is_dragging = sfFalse;
}

void on_hover(void *data, struct slot *s, sfRenderWindow *w)
{
    static sfBool is_pressed = 0;
    all_t *d = (all_t *)data;
    s->is_hover = 1;
    is_pressed = 0;
    hover_click(d, is_pressed, w, s);
    t_slot *tmp = d->s_game.inventory.drag_info.slot;
    if (tmp && tmp->has_item)
        on_drop(data, s, is_pressed);
    s->is_hover = 0;
    if (is_button_released(&d->s_game.event, sfMouseLeft))
        if (is_button_pressed(&d->s_game.event, sfMouseLeft))
            on_drag(d, s, w);
    if (is_button_released(&d->s_game.event, sfMouseRight))
        equip_weapon(d, s);
    if (!is_button_pressed(&d->s_game.event, sfMouseLeft)) {
        s->is_hover = 0;
        sfSprite_setColor(s->sprite_bg, (sfColor){255, 255, 255, 255});
    }
}
