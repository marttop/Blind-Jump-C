/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** items_database.c
*/

#include <items.h>

void add_weapon(t_node *inv, u_item *item)
{
    get_empty_slot(inv, item, WEAPON);
}
