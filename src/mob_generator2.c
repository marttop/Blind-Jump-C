/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_generator2
*/

#include "rpg.h"

void generate_random_mobs3(all_t *s_all)
{
    int x = s_all->s_map.x;
    int y = s_all->s_map.y - 1, randx = 0, randy = 0, i = 20;
    while (i != 0) {
        randx = (rand() % x);
        randy = (rand() % y);
        s_all->s_mob_pos.x = randx, s_all->s_mob_pos.y = randy;
        if (s_all->s_map.map[randy][randx] == '0' &&
        breadth_first_search_entity(s_all->s_map.map, s_all,
        randx, randy) != NULL) {
            s_all->s_mob = fill_mob(s_all->s_mob, 'T',
            (sfVector2f){randx * 32 + 17, randy * 26}, s_all);
            i--;
        }
    }
}