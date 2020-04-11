/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** vectors
*/

#include "rpg.h"

float calcul_mob_magnitude(mob_t *temp, sfSprite *sprite)
{
    sfVector2f pos_sprite = sfSprite_getPosition(sprite);
    float vx = temp->mob_pos.x - pos_sprite.x + 7;
    float vy = temp->mob_pos.y - pos_sprite.y + 4;
    float magnitude = sqrt(pow(vx, 2) + pow(vy, 2));
    return (magnitude);
}