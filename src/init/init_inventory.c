/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_inventory
*/

#include "rpg.h"

void set_texture_items(slots_t *tmp, int id, all_t *s_all)
{
    if (id == 1)
        sfSprite_setTexture(tmp->item, s_all->s_inventory.pistol, sfTrue);
    if (id == 2)
        sfSprite_setTexture(tmp->item, s_all->s_inventory.scorpion, sfTrue);
}

void init_slots(all_t *s_all, sfVector2f pos)
{
    slots_t *old = NULL;
    pos.x += 10, pos.y += 10;
    int x = pos.x;
    for (int i = 0, count = 0; i != 20; i++, count++) {
        slots_t *tmp = malloc(sizeof(slots_t));
        tmp->slot = sfSprite_create();
        sfSprite_setTexture(tmp->slot, s_all->s_inventory.slot_tx, sfTrue);
        sfSprite_setPosition(tmp->slot, pos);
        tmp->item = sfSprite_create();
        tmp->drag = 0;
        pos.x += 62;
        tmp->is_item = 0;
        if (count == 3)
            count = -1, pos.x = x, pos.y += 62;
        tmp->next = old;
        old = tmp;
    }
    s_all->s_inventory.head = old;
}

void init_items_texture(all_t *s_all)
{
    s_all->s_inventory.pistol =
        sfTexture_createFromFile("sprites/weapons/pistol.png", NULL);
    s_all->s_inventory.scorpion =
        sfTexture_createFromFile("sprites/weapons/scorpion.png", NULL);
}

void init_inventory(all_t *s_all)
{
    sfVector2f pos = {1500, 350};
    s_all->s_inventory.inv_back = sfRectangleShape_create();
    sfRectangleShape_setSize(s_all->s_inventory.inv_back,
        (sfVector2f) {269, 330});
    sfRectangleShape_setFillColor(s_all->s_inventory.inv_back,
        (sfColor){56, 79, 88, 160});
    sfRectangleShape_setPosition(s_all->s_inventory.inv_back, pos);
    s_all->s_inventory.slot_tx =
        sfTexture_createFromFile("sprites/inv/slot.png", NULL);
    s_all->s_inventory.selected_tx =
        sfTexture_createFromFile("sprites/inv/selector.png", NULL);
    s_all->s_inventory.selected = sfSprite_create();
    sfSprite_setTexture(s_all->s_inventory.selected,
        s_all->s_inventory.selected_tx, sfTrue);
    s_all->s_inventory.drag = 0, s_all->s_inventory.swap = 0;
    init_slots(s_all, pos);
    init_items_texture(s_all);
}