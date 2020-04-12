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

void iterate_slots(t_node *inv, all_t *d)
{
    t_node *tmp = inv;
    t_slot *slot = ((t_slot *)tmp->data);
    sfVector2f f_mp = get_mouse_inv_position(d);
    while (tmp->next)
    {
        slot = ((t_slot *)tmp->data);
        if (sfIntRect_contains(&slot->rect, f_mp.x, f_mp.y))
            slot->on_hover(d, slot, d->s_game.window);

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