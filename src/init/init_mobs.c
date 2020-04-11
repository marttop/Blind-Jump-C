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
    sfSprite_setPosition(new->mob, new->mob_pos);
    sfSprite_setPosition(new->shadow, new->shadow_pos);
}

void mob_selector(mob_t *new, char type, sfVector2f pos)
{
    sfSprite_setTextureRect(new->shadow, (sfIntRect){55, 69, 20, 6});
    sfSprite_setOrigin(new->shadow, (sfVector2f){10, 3});
    if (type == 'B') {
        new->mob_pos.x += 9, new->mob_pos.y += 9, new->speed = 2;
        new->shadow_pos = (sfVector2f){pos.x + 10, pos.y + 17};
        new->rect = (sfIntRect){0, 57, 18, 17};
        sfSprite_setOrigin(new->mob, (sfVector2f){9, 9});
    }
    if (type == 'A') {
        sfSprite_setScale(new->shadow, (sfVector2f){0.80, 0.80});
        new->mob_pos.x += 5, new->mob_pos.y += 5, new->speed = 1;
        new->shadow_pos = (sfVector2f){pos.x + 6, pos.y + 14};
        new->rect = (sfIntRect){88, 161, 12, 12};
        sfSprite_setOrigin(new->mob, (sfVector2f){6, 6});
    }
}

mob_t *fill_mob(mob_t *old, char type, sfVector2f pos, all_t *s_all)
{
    mob_t *new = malloc(sizeof(mob_t));
    new->mob_pos = pos;
    new->aggro = 0;
    new->x = s_all->s_mob_pos.x, new->y = s_all->s_mob_pos.y;
    new->clock = sfClock_create(), new->rect_clock = sfClock_create();
    new->mob = sfSprite_create(), new->shadow = sfSprite_create();
    new->mob_txt = s_all->s_player.hero_tx, new->seconds = 0;
    new->shadow_tx = s_all->s_player.hero_tx, new->prev = '@';
    new->path = breadth_first_search_entity(s_all->s_map.map,
    s_all, new->x, new->y), new->hor = 32, new->ver = 26;
    new->status = 0, new->rect_seconds = 0;
    sfSprite_setTexture(new->mob, new->mob_txt, sfTrue);
    sfSprite_setTexture(new->shadow, new->shadow_tx, sfTrue);
    mob_selector(new, type, pos);
    new->type = type, new->next = old;
    fill_mob2(new);
    return (new);
}

void move_mobs_rect(mob_t *mob, int max, int offset, int reset)
{
    if (mob->rect.left != max)
        mob->rect.left += offset;
    else mob->rect.left = reset;
    sfSprite_setTextureRect(mob->mob, mob->rect);
    sfClock_restart(mob->rect_clock);
}

void display_mobs(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    while (temp != NULL) {
        float magnitude = calcul_mob_magnitude(temp, s_all->s_player.shadow);
        if (magnitude <= 150) temp->aggro = 1;
        if (temp->seconds > 0.01 && temp->aggro == 1
        && s_all->s_player.tp == 0)
            search_mob_path(temp, s_all);
        if (temp->rect_seconds > 0.1 && temp->type == 'B' && temp->aggro == 1
        && s_all->s_player.tp == 0)
            move_mobs_rect(temp, 36, 18, 0);
        if (temp->rect_seconds > 0.1 && temp->type == 'A' && temp->aggro == 1
        && s_all->s_player.tp == 0)
            move_mobs_rect(temp, 100, 12, 88);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->shadow, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
        sfSprite_setPosition(temp->mob, temp->mob_pos);
        sfSprite_setPosition(temp->shadow, temp->shadow_pos);
        temp = temp->next;
    } check_mob_hitboxes(s_all);
    destroy_mobs(s_all);
}