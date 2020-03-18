/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** inventory.c
*/

#include <inventory.h>

void init_inventory(all_t *d)
{
    d->s_game.inv_pos = (sfVector2f){1500, 200};
    d->s_game.inv_tex = sfRenderTexture_create(256+30, 320+30, 0);
    d->s_game.inv_sprite = sfSprite_create();
    sfSprite_setPosition(d->s_game.inv_sprite, d->s_game.inv_pos);
    sfSprite_setTexture(d->s_game.inv_sprite,
        sfRenderTexture_getTexture(d->s_game.inv_tex), 1);
    generate_slots(d);
}

void generate_slots(all_t *d)
{
    int slot_amount = 20;
    int x_shift = 4;
    t_node *inv = malloc(sizeof(t_node));
    sfVector2f start_pos = (sfVector2f){15, 16};
    sfVector2f old_pos = (sfVector2f){start_pos.x, start_pos.y};
    sfVector2f new_pos = (sfVector2f){0, 0};
    inv->next = NULL;
    for (int i = 0; i < slot_amount; i++) {
        t_slot *slot = malloc(sizeof(t_slot));
        slot->id = i;
        slot->on_click = &on_click;
        slot->on_hover = &on_hover;
        slot->on_drag = &on_drag;
        slot->weapon = NULL;
        slot->has_item = 0;
        slot->texture_bg = sfTexture_createFromFile(
            "sprites/inv/slot.png", NULL);
        slot->texture_slect = sfTexture_createFromFile(
            "sprites/inv/selector.png", NULL);
        slot->sprite_bg = sfSprite_create();
        slot->sprite_select = sfSprite_create();
        slot->shape_hover = sfRectangleShape_create();
        sfSprite_setTexture(slot->sprite_select, slot->texture_slect, 1);
        sfSprite_setTexture(slot->sprite_bg, slot->texture_bg, 1);
        slot->rect = sfSprite_getTextureRect(slot->sprite_bg);
        sfIntRect r = slot->rect;
        sfRectangleShape_setSize(slot->shape_hover,
            (sfVector2f){slot->rect.width, slot->rect.height-6});
        sfRectangleShape_setOutlineThickness(slot->shape_hover, 1);
        sfRectangleShape_setOutlineColor(slot->shape_hover, sfBlue);
        sfRectangleShape_setFillColor(slot->shape_hover,
            (sfColor){0, 0, 0, 0});
        if (i > 0 && (i % x_shift) == 0) {
            old_pos.y += r.height;
            old_pos.x = start_pos.x;
            new_pos = (sfVector2f){old_pos.x, old_pos.y};
            sfSprite_setPosition(slot->sprite_bg, new_pos);
            sfRectangleShape_setPosition(slot->shape_hover, new_pos);
            sfSprite_setPosition(slot->sprite_select, new_pos);
        } else {
            if (i > 0) new_pos = (sfVector2f){old_pos.x += r.width, old_pos.y};
            else if (i == 0) new_pos = (sfVector2f){old_pos.x, old_pos.y};
            sfSprite_setPosition(slot->sprite_bg, new_pos);
            sfRectangleShape_setPosition(slot->shape_hover, new_pos);
            sfSprite_setPosition(slot->sprite_select, new_pos);
        }
        slot->rect.left = new_pos.x, slot->rect.top = new_pos.y;
        sfRectangleShape_setTextureRect(slot->shape_hover,
            (sfIntRect){r.height, r.left, r.top, r.width});
        inv = add_node(inv, slot);
    }
    d->s_game.inv = inv;
}

void draw_inventory(all_t *d)
{
    sfRenderTexture_clear(d->s_game.inv_tex , (sfColor){70, 105, 104, 133});
    sfRenderTexture_display(d->s_game.inv_tex);
    draw_slots(d->s_game.inv, d->s_game.inv_tex, d);
    iterate_slots(d->s_game.inv, d);
    sfRenderWindow_drawSprite(d->s_game.window, d->s_game.inv_sprite, NULL);
}