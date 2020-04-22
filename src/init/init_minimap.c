/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_minimap
*/

#include "rpg.h"

void init_minimap(all_t *s_all)
{
    static int i = 0;
    s_all->s_minimap.sprite = sfSprite_create();
    sfSprite_setTexture(s_all->s_minimap.sprite,
        s_all->s_map.map_texture, sfTrue);
    if (i == 0) {
        s_all->s_minimap.black = sfSprite_create();
        sfSprite_setTexture(s_all->s_minimap.black,
        sfTexture_createFromFile("sprites/rounded_black.png", NULL), sfTrue);
        sfSprite_setScale(s_all->s_minimap.black, (sfVector2f){1.24, 0.86});
        sfSprite_setColor(s_all->s_minimap.black,
            (sfColor){255, 255, 255, 150});
    }
    sfSprite_setScale(s_all->s_minimap.sprite, (sfVector2f){0.2, -0.2});
    sfSprite_setPosition(s_all->s_minimap.sprite, (sfVector2f){20, 230});
    sfSprite_setPosition(s_all->s_minimap.black, (sfVector2f){-41, -66});
    sfSprite_setColor(s_all->s_minimap.sprite, (sfColor){255, 255, 255, 150});
    i = 1;
}