/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs
*/

#include "rpg.h"

void fill_mob2(mob_t *new)
{
    new->refresh_clk = sfClock_create();
    sfSprite_setTextureRect(new->mob, new->rect);
    sfSprite_setTextureRect(new->shadow, (sfIntRect){55, 69, 20, 6});
    sfSprite_setPosition(new->mob, new->mob_pos);
    sfSprite_setPosition(new->shadow, new->shadow_pos);
}

mob_t *fill_mob(mob_t *old, char type, sfVector2f pos, all_t *s_all)
{
    mob_t *new = malloc(sizeof(mob_t));
    new->x = s_all->s_mob_pos.x, new->y = s_all->s_mob_pos.y;
    new->clock = sfClock_create(), new->rect_clock = sfClock_create();
    new->mob = sfSprite_create(), new->shadow = sfSprite_create();
    new->mob_pos = pos, new->shadow_pos = (sfVector2f){pos.x + 1, pos.y + 11};
    new->mob_txt = s_all->s_player.hero_tx, new->seconds = 0;
    new->shadow_tx = s_all->s_player.hero_tx, new->prev = '@';
    new->path = breadth_first_search_entity(s_all->s_map.map,
    s_all, new->x, new->y), new->hor = 32, new->ver = 26, new->speed = 2;
    sfSprite_setTexture(new->mob, new->mob_txt, sfTrue);
    sfSprite_setTexture(new->shadow, new->shadow_tx, sfTrue);
    new->rect = (sfIntRect){0, 60, 18, 20};
    new->type = type, new->next = old;
    fill_mob2(new);
    return (new);
}

void display_mobs(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    while (temp != NULL) {
        if (temp->seconds > 0.01)
            search_mob_path(temp, s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->shadow, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
        sfSprite_setPosition(temp->mob, temp->mob_pos);
        sfSprite_setPosition(temp->shadow, temp->shadow_pos);
        temp = temp->next;
    }
}