/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** weapon.c
*/

#include <items.h>

t_weapon *create_pistol(void)
{
    static int ID = 0;
    t_weapon *tmp = malloc(sizeof(t_weapon));
    tmp->id = ID++;
    tmp->name = "Pistol";
    tmp->range = 10.f;
    tmp->type = SINGLE_SHOT;
    tmp->sprite = sfSprite_create();
    sfSprite_setTexture(tmp->sprite,
    sfTexture_createFromFile("sprites/weapons/pistol.png", NULL), 1);
    return tmp;
}