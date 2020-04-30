/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_inventory3
*/

#include "rpg.h"

void display_inventory_inf(all_t *s_all, int check)
{
    if (check == 1) {
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_inventory.infos, NULL);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_inventory.infos_text, NULL);
    }
}

void init_under(all_t *s_all, sfVector2f pos, int id, slots_t *tmp)
{
    tmp->under = sfSprite_create();
    if (id != 5)
        sfSprite_setTexture(tmp->under, s_all->s_inventory.armors_tx, sfTrue);
    else sfSprite_setTexture(tmp->under, s_all->s_inventory.pistol, sfTrue);
    if (id == 1) {
        sfSprite_setTextureRect(tmp->under, (sfIntRect){0, 128, 64, 64});
    } if (id == 2) {
        sfSprite_setTextureRect(tmp->under, (sfIntRect){64, 128, 64, 64});
    } if (id == 3) {
        sfSprite_setTextureRect(tmp->under, (sfIntRect){128, 128, 64, 64});
    } if (id == 4) {
        sfSprite_setTextureRect(tmp->under, (sfIntRect){196, 128, 64, 64});
    } sfSprite_setColor(tmp->under, (sfColor){0, 0, 0, 50});
    sfSprite_setPosition(tmp->under, pos);
}

void init_equip_slots(all_t *s_all)
{
    slots_t *old = s_all->s_inventory.head;
    sfVector2f pos = {430, 370};
    for (int i = 1; i != 6; i++, pos.y += 62) {
        slots_t *tmp = malloc(sizeof(slots_t));
        tmp->slot = sfSprite_create();
        sfSprite_setTexture(tmp->slot, s_all->s_inventory.slot_tx, sfTrue);
        sfSprite_setPosition(tmp->slot, pos);
        tmp->item = sfSprite_create();
        tmp->drag = 0, tmp->health = 0, tmp->dmg = 0;
        tmp->equip = 1;
        tmp->is_item = 0;
        tmp->next = old;
        tmp->slot_nb = i;
        init_under(s_all, pos, i, tmp);
        old = tmp;
        if (i == 4) pos.x += 100, pos.y += 45;
    } s_all->s_inventory.head = old;
}