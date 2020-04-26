/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_inventory
*/

#include "rpg.h"

void trash_items(all_t *s_all)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect rect = sfSprite_getGlobalBounds(s_all->s_inventory.trash);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1
    && s_all->s_inventory.drag == 1
    && s_all->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
        s_all->s_inventory.dragged->drag = 0;
        s_all->s_inventory.drag = 0;
        s_all->s_inventory.dragged->id = 0;
        s_all->s_inventory.dragged->is_item = 0;
        sfSprite_destroy(s_all->s_inventory.dragged->item);
        s_all->s_inventory.dragged->item = sfSprite_create();
        s_all->s_game.event.mouseButton.type = 0;
        s_all->s_inventory.dragged = NULL;
    }
}

void display_items_and_select(all_t *s_all)
{
    slots_t *tmp = s_all->s_inventory.head;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    for (; tmp != NULL; tmp = tmp->next) { 
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->slot);
        rect.width -= 2, rect.left += 1;
        rect.height -= 2, rect.top += 1;
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1) {
            slot_click(s_all, tmp);
            sfSprite_setPosition(s_all->s_inventory.selected,
                sfSprite_getPosition(tmp->slot));
            sfRenderWindow_drawSprite(s_all->s_game.window,
                s_all->s_inventory.selected, NULL);
        } if (tmp->item != NULL && tmp->drag != 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->item, NULL);
    } drag_item(s_all);
    trash_items(s_all);
}

void display_inventory(all_t *s_all)
{
    slots_t *tmp = s_all->s_inventory.head;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_inventory.inv_back, NULL);
    for (; tmp != NULL; tmp = tmp->next) { 
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->slot, NULL);
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->slot);
        rect.width -= 2, rect.left += 1;
        rect.height -= 2, rect.top += 1;
        sfSprite_setColor(tmp->slot, (sfColor){255, 255, 255, 255});
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1) {
            sfSprite_setPosition(s_all->s_inventory.selected,
                sfSprite_getPosition(tmp->slot));
            sfRenderWindow_drawSprite(s_all->s_game.window,
                s_all->s_inventory.selected, NULL);
        } if (tmp->item != NULL && tmp->drag != 1)
            sfRenderWindow_drawSprite(s_all->s_game.window, tmp->item, NULL);
    } sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_inventory.trash, NULL);
    display_items_and_select(s_all);
}