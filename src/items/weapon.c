/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** weapon.c
*/

#include <items.h>

u_item *create_pistol(void)
{
    u_item *tmp = malloc(sizeof(u_item));
    tmp->weapon.id = 0;
    tmp->weapon.name = "Pistol";
    tmp->weapon.range = 10.f;
    tmp->weapon.type = SINGLE_SHOT;
    tmp->weapon.sprite = sfSprite_create();
    sfSprite_setTexture(tmp->weapon.sprite,
    sfTexture_createFromFile("sprites/weapons/pistol.png", NULL), 1);
    return tmp;
}

u_item *create_scorpion(void)
{
    u_item *tmp = malloc(sizeof(u_item));
    tmp->weapon.id = 1;
    tmp->weapon.name = "Scorpion";
    tmp->weapon.range = 13.f;
    tmp->weapon.type = SINGLE_SHOT;
    tmp->weapon.sprite = sfSprite_create();
    sfSprite_setTexture(tmp->weapon.sprite,
    sfTexture_createFromFile("sprites/weapons/scorpion.png", NULL), 1);
    return tmp;
}