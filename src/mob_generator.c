/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_generator
*/

#include "rpg.h"

void free_all_mobs(all_t *s_all)
{
    mob_t *temp;
    mob_t *head = s_all->s_mob;
    while (head != NULL) {
        temp = head->next;
        sfSprite_destroy(head->mob);
        sfClock_destroy(head->rect_clock);
        sfClock_destroy(head->clock);
        free(head);
        head = temp;
    }
    s_all->s_mob = NULL;
}

void generate_random_mobs(all_t *s_all)
{
    int x = s_all->s_map.x;
    int y = s_all->s_map.y - 1;
    int randx = 0;
    int randy = 0;
    int i = 70;
    free_all_mobs(s_all);
    while (i != 0) {
        randx = (rand() % x);
        randy = (rand() % y);
        s_all->s_mob_pos.x = randx, s_all->s_mob_pos.y = randy;
        if (s_all->s_map.map[randy][randx] == '0') {
            s_all->s_mob = fill_mob(s_all->s_mob, 'B',
            (sfVector2f){randx * 32 + 8, randy * 26 + 5}, s_all);
            i--;
        }
    }
}