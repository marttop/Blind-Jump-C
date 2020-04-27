/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_custom2
*/

#include "rpg.h"

// void fill_rbg(all_t *s_all, int value, char type)
// {
//     s_all-
// }

void init_rgb_selector(all_t *s_all)
{
    int r, g, b;
    sfColor color = sfSprite_getColor(s_all->s_custom.hero);
    r = color.r, g = color.g, b = color.b;
    s_all->s_rgb = NULL;
}