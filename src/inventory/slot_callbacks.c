/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** slot_callbacks.c
*/

#include <inventory.h>

void draw_slots(t_node *inv, sfRenderTexture *inv_tex, all_t *d)
{
    d->item_db.weapons->id = 0;
    t_node *tmp = inv;
    while (tmp->next) {
        t_slot *slot = (t_slot *)tmp->data;
        sfRenderTexture_drawSprite(inv_tex, slot->sprite_bg, NULL);
        if (slot->item != NULL && !slot->is_dragging) {
            sfSprite_setPosition(slot->item->weapon.sprite,
                sfSprite_getPosition(slot->sprite_bg));
            sfRenderTexture_drawSprite(inv_tex,
                slot->item->weapon.sprite, NULL);
        }
        tmp = tmp->next;
    }
}

void on_left_click(void *data, struct slot *s, sfRenderWindow *w)
{
    sfSprite_setColor(s->sprite_bg, (sfColor){0, 0, 0, 110});
    return;
}

void on_drag(void *data, struct slot *s, sfRenderWindow *w)
{
    all_t *d = (all_t *)data;
    sfVector2i m = sfMouse_getPositionRenderWindow(w);
    sfVector2f m_pos = sfRenderWindow_mapPixelToCoords(w,
        sfMouse_getPositionRenderWindow(w), sfRenderWindow_getDefaultView(w));
    sfVector2f g_pos = (sfVector2f){m.x, m.y};
    sfSprite_setPosition(d->s_game.inventory.dragtip.render_sprite, g_pos);
}

void on_drop(void *data, t_slot *s)
{
    all_t *d = (all_t *)data;
    t_slot *tmp = d->s_game.inventory.drag_info.slot;
    sfBool is_released = is_button_released(&d->s_game.event, sfMouseLeft);
    s->is_pressed = 0;
    if (tmp != s && !tmp->is_dragging && is_released) {
        if (s->item == NULL) {
            s->item = tmp->item;
            s->has_item = 1;
            s->type = tmp->type;
            tmp->item = NULL;
            tmp->has_item = 0;
            tmp->type = -1;
        }
        else {
            u_item *tmp1 = s->item;
            s->item = tmp->item;
            tmp->item = tmp1;
        }
    }
}