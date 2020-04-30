/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chatbox2
*/

#include "rpg.h"

void init_chatbox2(all_t *s_all)
{
    s_all->s_chatbox.eric = sfSprite_create();
    s_all->s_chatbox.eric_tx =
        sfTexture_createFromFile("sprites/eric.png", NULL);
    sfSprite_setTexture(s_all->s_chatbox.eric,
        s_all->s_chatbox.eric_tx, sfTrue);
    sfSprite_setPosition(s_all->s_chatbox.eric, (sfVector2f){1620, 790});
}