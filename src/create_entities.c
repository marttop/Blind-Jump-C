/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** create_sprite
*/

#include "rpg.h"

void create_sprite(sfSprite **sprite, sfTexture **texture,
    sfVector2f pos, const char *path)
{
    *sprite = sfSprite_create();
    *texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(*sprite, *texture, sfTrue);
    sfFloatRect bounds = sfSprite_getLocalBounds(*sprite);
    sfSprite_setOrigin(*sprite,
        (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfSprite_setPosition(*sprite, pos);
}