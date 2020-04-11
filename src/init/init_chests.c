/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_chests
*/

#include "rpg.h"

chest_t *fill_chests(chest_t *old, all_t *s_all, sfVector2f pos)
{
    chest_t *new = malloc(sizeof(chest_t));
    new->sprite = sfSprite_create();
    new->texture = s_all->s_player.hero_tx;
    new->clock = sfClock_create();
    new->rect = (sfIntRect){656, 77, 16, 29};
    new->pos = pos, new->seconds = 0;
    new->status = 0;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setPosition(new->sprite, new->pos);
    new->next = old;
    return (new);
}

void open_chest(chest_t *temp)
{
    if (temp->seconds > 0.1) {
        if (temp->rect.left < 736) {
            temp->rect.left += 16;
            sfSprite_setTextureRect(temp->sprite, temp->rect);
        }
        else {
            temp->status = -1;
        }
        sfClock_restart(temp->clock);
    }
}

void display_chests_over(all_t *s_all, int y)
{
    chest_t *temp = s_all->s_chest;
    while (temp != NULL) {
        if (temp->status == 1)
            open_chest(temp);
        if (temp->pos.y + 14 >= y)
            sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
}

int display_chests_under(all_t *s_all)
{
    chest_t *temp = s_all->s_chest;
    int y = sfSprite_getPosition(s_all->s_player.shadow).y;
    while (temp != NULL) {
        if (temp->status == 1)
            open_chest(temp);
        if (temp->pos.y + 14 < y)
            sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
    return (y);
}