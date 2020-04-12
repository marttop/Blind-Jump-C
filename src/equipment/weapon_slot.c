/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** weapon_slot.c
*/

#include "rpg.h"
#include "inventory.h"
#include "equipment.h"

void init_weapon_slot(all_t *s_all)
{
    sfTexture *tex_slot = sfTexture_createFromFile(
        "sprites/inv/slot.png", NULL);
    sfTexture *tex_selector = sfTexture_createFromFile(
        "sprites/inv/selector.png", NULL);
    t_slot *s = malloc(sizeof(t_slot));
    s->is_dragging = 0, s->is_hover = 0, s->has_item = 0, s->id = 100;
    s->item = NULL;
    s->type = -1;
    s->on_hover = &on_hover;
    s->on_click = &on_click;
    s->texture_bg = tex_slot;
    s->texture_slect = tex_selector;
    s->sprite_bg = sfSprite_create();
    s->sprite_select = sfSprite_create();
    sfSprite_setTexture(s->sprite_select, s->texture_slect, 1);
    sfSprite_setTexture(s->sprite_bg, s->texture_bg, 1);
    sfSprite_setPosition(s->sprite_bg, (sfVector2f){0, 0});
    sfSprite_setPosition(s->sprite_select, (sfVector2f){0, 0});
    s->rect = sfSprite_getTextureRect(s->sprite_bg);
    s_all->s_game.equipment.slot_w = s;
}

void draw_weapon_slot(all_t *s_all)
{
    t_equipment *e = &s_all->s_game.equipment;
    sfRenderTexture_drawSprite(e->render_tex, e->slot_w->sprite_bg, NULL);
    if (e->slot_w->has_item && e->slot_w->item != NULL) {
        sfRenderTexture_drawSprite(e->render_tex,
            e->slot_w->item->weapon.sprite, NULL);
    }
}

void equip_weapon(all_t *s_all, t_slot *slot)
{
    sfVector2f zero = (sfVector2f){0, 0};
    t_equipment *e = &s_all->s_game.equipment;
    if (e->slot_w->has_item && slot->item != NULL && slot->type == WEAPON) {
        u_item *tmp = e->slot_w->item;
        e->slot_w->item = slot->item;
        sfSprite_setPosition(e->slot_w->item->weapon.sprite, zero);
        slot->item = tmp;
        sfSprite_setPosition(slot->item->weapon.sprite, slot->pos);
        return;
    }
    if (!e->slot_w->has_item && slot->item != NULL && slot->type == WEAPON) {
        e->slot_w->has_item = 1;
        e->slot_w->item = slot->item;
        sfSprite_setPosition(e->slot_w->item->weapon.sprite, zero);
        slot->has_item = 0;
        slot->type = -1;
        slot->item = NULL;
    }
}