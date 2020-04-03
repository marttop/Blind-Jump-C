/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_movements
*/

#include "rpg.h"

void move_mob_up(mob_t *node, all_t *s_all)
{
    if (node->ver > 0) {
        node->mob_pos.y -= node->speed;
        node->shadow_pos.y -= node->speed;
        node->ver -= node->speed;
    } else {
        node->prev = 'U';
        node->y -= 1;
        node->ver = 26;
    } sfClock_restart(node->clock);
}

void move_mob_right(mob_t *node, all_t *s_all)
{
    if (node->hor > 0) {
        node->mob_pos.x += node->speed;
        node->shadow_pos.x += node->speed;
        node->hor -= node->speed;
    } else {
        node->prev = 'R';
        node->x += 1;
        node->hor = 32;
    } sfClock_restart(node->clock);
}

void move_mob_down(mob_t *node, all_t *s_all)
{
    if (node->ver > 0) {
        node->mob_pos.y += node->speed;
        node->shadow_pos.y += node->speed;
        node->ver -= node->speed;
    } else {
        node->prev = 'D';
        node->y += 1;
        node->ver = 26;
    } sfClock_restart(node->clock);
}

void move_mob_left(mob_t *node, all_t *s_all)
{
    if (node->hor > 0) {
        node->mob_pos.x -= node->speed;
        node->shadow_pos.x -= node->speed;
        node->hor -= node->speed;
    } else {
        node->prev = 'L';
        node->x -= 1;
        node->hor = 32;
    } sfClock_restart(node->clock);
}