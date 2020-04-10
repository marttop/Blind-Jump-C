/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** slot_callbacks.c
*/

#include <inventory.h>

void draw_slots(t_node *inv, sfRenderTexture *inv_tex, all_t *d)
{
    d->item_db.weapons->id=0;
    t_node *tmp = inv;
    while (tmp->next)
    {
        t_slot *slot = (t_slot *)tmp->data;
        sfRenderTexture_drawSprite(inv_tex, slot->sprite_bg, NULL);
        if (slot->item != NULL && !slot->is_dragging)
        {
            sfSprite_setPosition(slot->item->weapon.sprite,
                sfSprite_getPosition(slot->sprite_bg));
            sfRenderTexture_drawSprite(inv_tex,
                slot->item->weapon.sprite, NULL);
        }
        tmp = tmp->next;
    }
}

void on_click(void *data, struct slot *s, sfRenderWindow *w)
{
    data;
    sfSprite_setColor(s->sprite_bg, (sfColor){100, 100, 100, 255});
    return;
}

void on_drag(void *data, struct slot *s, sfRenderWindow *w)
{
    sfVector2f m_pos = sfRenderWindow_mapPixelToCoords(w,
        sfMouse_getPositionRenderWindow(w), sfRenderWindow_getDefaultView(w));
    s->is_dragging = sfTrue;
    sfSprite_setPosition(s->item->weapon.sprite, m_pos);
}

sfBool on_drop(void *data, t_slot *s, sfBool is_pressed)
{
    all_t *d = (all_t *)data;
    t_slot *tmp = d->s_game.inventory.drag_info.slot;
    sfBool is_released = is_button_released(&d->s_game.event, sfMouseLeft);
    if (tmp != s && !tmp->is_dragging && is_released)
    {
        if (s->item == NULL)
        {
            s->item = tmp->item;
            s->has_item = 1;
            tmp->item = NULL;
            tmp->has_item = 0;
            return sfFalse;
        }
        else
        {
            u_item *tmp1 = s->item;
            s->item = tmp->item;
            tmp->item = tmp1;
        }
    }
    return sfFalse;
}

void on_hover(void *data, struct slot *s, sfRenderWindow *w)
{
    static sfBool is_pressed = 0;
    all_t *d = (all_t *)data;
    s->is_hover = 1;
    is_pressed = 0;
    sfRenderTexture_drawSprite(d->s_game.inventory.inv_tex,
                               s->sprite_select, NULL);
    if (is_button_pressed(&d->s_game.event, sfMouseLeft))
    {
        d->s_game.inventory.drag_info.slot = s;
        is_pressed = sfTrue;
        on_click(d, s, w);
    }
    else
        sfSprite_setColor(s->sprite_bg, (sfColor){255, 255, 255, 255});

    t_slot *tmp = d->s_game.inventory.drag_info.slot;

    if (tmp && tmp->has_item)
        on_drop(data, s, is_pressed);

    if (is_pressed && d->s_game.event.mouseMove.type == sfEvtMouseMoved)
    {
        if (d->s_game.inventory.drag_info.slot->has_item)
        {
            on_drag(d, d->s_game.inventory.drag_info.slot, w);
        }
    }
    else
        s->is_dragging = sfFalse;
    s->is_hover = 0;
    if (is_button_released(&d->s_game.event, sfMouseLeft))
        if (is_button_pressed(&d->s_game.event, sfMouseLeft))
            on_drag(d, s, w);

    if (!is_button_pressed(&d->s_game.event, sfMouseLeft))
    {
        s->is_hover = 0;
        sfSprite_setColor(s->sprite_bg, (sfColor){255, 255, 255, 255});
    }
}
