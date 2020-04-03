/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_path
*/

#include "rpg.h"

void refresh_path_to_player(all_t *s_all)
{
    mob_t *node = s_all->s_mob;
    while (node != NULL) {
        free_map(node->path);
        node->path = breadth_first_search_entity(s_all->s_map.map,
        s_all, node->x, node->y);
        node = node->next;
    }
}

void search_mob_path(mob_t *node, all_t *s_all)
{
    int x = node->x, y = node->y;
    if (node->path == NULL) return;
    if (node->y != 0) {
        if (node->y != 0 && node->path[y - 1][x] == ' ' && node->prev != 'D')
            move_mob_up(node, s_all);
        }
    if (node->path[y][x + 1] == ' ' && node->prev != 'L')
        move_mob_right(node, s_all);
    if (node->y != s_all->s_map.y - 1) {
        if (node->y != s_all->s_map.y - 1 && node->path[y + 1][x] == ' ' &&
        node->prev != 'U')
            move_mob_down(node, s_all);
    }
    if (node->x != 0) {
        if (node->x != 0 && node->path[y][x - 1] == ' ' && node->prev != 'R')
            move_mob_left(node, s_all);
    }
}