/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** slot_utils.c
*/

#include <rpg.h>

sfVector2f get_mouse_inv_position(all_t *d)
{
    sfVector2f pos;
    sfVector2f p = d->s_game.inventory.inv_pos;
    sfVector2i mp = sfMouse_getPositionRenderWindow(d->s_game.window);
    pos = sfRenderWindow_mapPixelToCoords(d->s_game.window, mp,
            sfRenderWindow_getView(d->s_game.window));
    return (sfVector2f){pos.x - p.x, pos.y - p.y};
}

void drag_update(all_t *d)
{
    static int holding = 0;
    t_drag_info *drag_info = &d->s_game.inventory.drag_info;
    if (d->s_game.inventory.drag_info.slot &&
        d->s_game.inventory.drag_info.slot->is_dragging) {
        on_drag(d, d->s_game.inventory.drag_info.slot, d->s_game.window);
    }
    if (drag_info->slot && is_button_pressed(&d->s_game.event, sfMouseLeft))
        holding = 1;
    if (drag_info->slot && drag_info->slot->item && holding == 1 &&
        d->s_game.event.type == sfEvtMouseMoved) {
        drag_info->slot->is_dragging = 1;
    }
    if (drag_info->slot && drag_info->slot->item &&
        d->s_game.event.mouseButton.button == sfMouseLeft &&
        d->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
        holding = 0;
        drag_info->slot->is_dragging = 0;
    }
}

void iterate_slots(t_node *inv, all_t *d)
{
    t_node *tmp = inv;
    t_slot *slot = ((t_slot *)tmp->data);
    sfVector2f f_mp = get_mouse_inv_position(d);
    drag_update(d);
    weapon_slot_update(d);
    while (tmp->next)
    {
        slot = ((t_slot *)tmp->data);
        if (sfIntRect_contains(&slot->rect, f_mp.x, f_mp.y)) {
            slot->on_hover(d, slot, d->s_game.window);
            slot->is_hover = 1;
        } else {
            sfSprite_setColor(slot->sprite_bg, (sfColor){255, 255, 255, 255});
            slot->is_hover = 0;
            slot->is_pressed = 0;
            slot->is_hover = 0;
        }
        tmp = tmp->next;
    }
}

void get_empty_slot(t_node *inv, u_item *item, e_item_type type)
{
    t_node *tmp = inv;
    t_slot *slot;
    while (tmp->next) {
        slot = ((t_slot *)tmp->data);
        if (!slot->has_item) {
            slot->item = item;
            slot->has_item = 1;
            slot->type = type;
            break;
        }
        tmp = tmp->next;
    }
}