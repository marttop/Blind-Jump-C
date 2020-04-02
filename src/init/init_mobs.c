/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs
*/

#include "rpg.h"

mob_t *fill_mob(mob_t *old, char type, sfVector2f pos, all_t *s_all)
{
    mob_t *new = malloc(sizeof(mob_t));
    new->mob = sfSprite_create();
    new->mob_pos = pos;
    new->mob_txt = s_all->s_player.hero_tx;
    sfSprite_setTexture(new->mob, new->mob_txt, sfTrue);
    new->rect = (sfIntRect){0, 60, 18, 20};
    sfSprite_setTextureRect(new->mob, new->rect);
    sfSprite_setPosition(new->mob, s_all->s_player.hero_pos);
    new->next = old;
    return (new);
}

void init_mobs(all_t *s_all)
{
    sfVector2f pos;
    pos.x = 500, pos.y = 500;
    s_all->s_mob = NULL;
    for (int i = 0; i != 1; i++) {
        s_all->s_mob = fill_mob(s_all->s_mob, 'B', pos, s_all);
    }
}

void display_mobs(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    while (temp != NULL) {
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
        temp = temp->next;
    }
}