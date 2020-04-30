/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_health_drop
*/

#include "rpg.h"

void display_hearth(all_t *s_all)
{
    hearth_t *tmp = s_all->s_life;
    for (; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->hearth, NULL);
}

void push_front_hearth(all_t *s_all, mob_t *tmp)
{
    hearth_t *life = malloc(sizeof(hearth_t));
    life->hearth = sfSprite_create();
    life->life = 10;
    sfSprite_setTexture(life->hearth, s_all->s_game.hearth_tx, sfTrue);
    if (tmp->type == 'A')
        sfSprite_setPosition(life->hearth, (sfVector2f){tmp->mob_pos.x - 7,
            tmp->mob_pos.y - 9});
    else
        sfSprite_setPosition(life->hearth, (sfVector2f){tmp->mob_pos.x - 10,
            tmp->mob_pos.y - 5});
    sfSprite_setTextureRect(life->hearth, (sfIntRect){0, 0, 46, 46});
    sfSprite_setScale(life->hearth, (sfVector2f){0.4, 0.4});
    life->next = s_all->s_life;
    s_all->s_life = life;
}