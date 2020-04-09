/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** inventory.c
*/

#include <inventory.h>

void init_inventory(all_t *s_all)
{
    t_inventory *inv = &s_all->s_game.inventory;
    init_tooltip(s_all);
    inv->inv_pos = (sfVector2f){1500, 150};
    inv->inv_tex = sfRenderTexture_create(256 + 30, 320 + 30, 0);
    inv->inv_sprite = sfSprite_create();
    inv->drag_info.slot = NULL;
    inv->drag_info.item = NULL;
    sfSprite_setPosition(inv->inv_sprite,
        inv->inv_pos);
    sfSprite_setTexture(inv->inv_sprite,
        sfRenderTexture_getTexture(inv->inv_tex), 1);
    generate_slots(s_all);
}

t_slot *test(t_slot *slot, sfTexture *tex_slot, sfTexture *tex_selector, int i)
{
    slot->id = i;
    slot->on_click = &on_click;
    slot->on_hover = &on_hover;
    slot->on_drag = &on_drag;
    slot->item = NULL;
    slot->has_item = 0;
    slot->is_dragging = sfFalse;
    slot->texture_bg = tex_slot;
    slot->texture_slect = tex_selector;
    slot->sprite_bg = sfSprite_create();
    slot->sprite_select = sfSprite_create();
    sfSprite_setTexture(slot->sprite_select, slot->texture_slect, 1);
    sfSprite_setTexture(slot->sprite_bg, slot->texture_bg, 1);
    slot->rect = sfSprite_getTextureRect(slot->sprite_bg);
    return slot;
}

void generate_slots(all_t *d)
{
    int slot_amount = 20;
    int x_shift = 4;
    t_node *inv = malloc(sizeof(t_node));
    sfVector2f start_pos = (sfVector2f){15, 16};
    sfVector2f old_pos = (sfVector2f){start_pos.x, start_pos.y};
    sfVector2f new_pos = (sfVector2f){0, 0};
    sfTexture *tex_slot = sfTexture_createFromFile(
        "sprites/inv/slot.png", NULL);
    sfTexture *tex_selector = sfTexture_createFromFile(
        "sprites/inv/selector.png", NULL);
    inv->next = NULL;
    for (int i = 0; i < slot_amount; i++) {
        t_slot *slot = malloc(sizeof(t_slot));
        slot = test(slot, tex_slot, tex_selector, i);
        sfIntRect r = slot->rect;
        if (i > 0 && (i % x_shift) == 0) {
            old_pos.y += r.height;
            old_pos.x = start_pos.x;
            new_pos = (sfVector2f){old_pos.x, old_pos.y};
            sfSprite_setPosition(slot->sprite_bg, new_pos);
            sfSprite_setPosition(slot->sprite_select, new_pos);
        } else {
            if (i > 0) new_pos = (sfVector2f){old_pos.x += r.width, old_pos.y};
            else if (i == 0) new_pos = (sfVector2f){old_pos.x, old_pos.y};
            sfSprite_setPosition(slot->sprite_bg, new_pos);
            sfSprite_setPosition(slot->sprite_select, new_pos);
        }
        slot->rect.left = new_pos.x, slot->rect.top = new_pos.y;
        inv = add_node(inv, slot);
    }
    d->s_game.inventory.inv = inv;
}

void draw_inventory(all_t *d)
{
    sfRenderTexture_clear(d->s_game.inventory.inv_tex,
        (sfColor){70, 105, 104, 133});
    sfRenderTexture_display(d->s_game.inventory.inv_tex);
    draw_slots(d->s_game.inventory.inv, d->s_game.inventory.inv_tex, d);
    iterate_slots(d->s_game.inventory.inv, d);
    sfRenderWindow_drawSprite(d->s_game.window,
        d->s_game.inventory.inv_sprite, NULL);
}