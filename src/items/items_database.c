/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** items_database.c
*/

#include <items.h>

void init_item_db(all_t *s_all)
{

}

void add_pistol(t_node *inv)
{
    t_weapon *tmp = create_pistol();
    get_empty_slot(inv, tmp);
}