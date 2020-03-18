/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** slot_callbacks.c
*/

#include <inventory.h>

void draw_slots(t_node *inv, sfRenderTexture *inv_tex, all_t *d)
{
    t_node *tmp = inv;
    while (tmp->next)
    {
        t_slot *slot = (t_slot *)tmp->data;
        sfRenderTexture_drawSprite(inv_tex, slot->sprite_bg, NULL);
        if (slot->weapon != NULL) {
            sfSprite_setPosition(slot->weapon->sprite,
                sfSprite_getPosition(slot->sprite_bg));
            sfRenderTexture_drawSprite(inv_tex, slot->weapon->sprite, NULL);
        }
        tmp = tmp->next;
    }
}

void on_click(void *d, struct slot *s, sfRenderWindow *w)
{
    sfSprite_setColor(s->sprite_bg, (sfColor){100, 100, 100, 255});
    return;
}

void on_drag(void *d, struct slot *s, sfRenderWindow *w)
{

}

void on_hover(void *data, struct slot *s, sfRenderWindow *w)
{
    all_t *d = (all_t *)data;
    sfVector2f p = d->s_game.inv_pos;
    sfVector2i mp = sfMouse_getPositionRenderWindow(w);
    sfVector2f f_mp = sfRenderWindow_mapPixelToCoords(w, mp,
        sfRenderWindow_getView(w));
    mp = sfRenderTexture_mapCoordsToPixel(d->s_game.inv_tex, f_mp,
        sfRenderWindow_getView(w));
    if (sfIntRect_contains(&s->rect, f_mp.x - p.x, f_mp.y - p.y)) {
        s->is_hover = 1;
        sfRenderTexture_drawSprite(d->s_game.inv_tex, s->sprite_select, NULL);
        if (is_button_pressed(&d->s_game.event, sfMouseLeft)) {
            on_click(d, s, w);
        }
        else sfSprite_setColor(s->sprite_bg, (sfColor){255, 255, 255, 255});
        if (is_button_released(&d->s_game.event, sfMouseLeft))
        if (is_button_pressed(&d->s_game.event, sfMouseLeft))
            on_drag(d, s, w);
    }
    s->is_hover = 0;
}