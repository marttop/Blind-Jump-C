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
    new->rect = (sfIntRect){657, 77, 15, 31};
    new->pos = pos, new->seconds = 0;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setPosition(new->sprite, new->pos);
    new->next = old;
    return (new);
}

void display_chests(all_t *s_all)
{
    chest_t *temp = s_all->s_chest;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->sprite, NULL);
        temp = temp->next;
    }
}