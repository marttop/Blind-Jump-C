/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mob_hitbox
*/

#include "rpg.h"

void check_mob_hitboxes(all_t *s_all)
{
    mob_t *temp = s_all->s_mob;
    sfFloatRect mob_rect, ver_rect, hor_rect;
    while (temp != NULL) {
        if (s_all->s_player.shooting == 0) break;
        mob_rect = sfSprite_getGlobalBounds(temp->mob);
        ver_rect = sfSprite_getGlobalBounds(s_all->s_player.ver_shoot);
        hor_rect = sfSprite_getGlobalBounds(s_all->s_player.hor_shoot);
        if (sfFloatRect_intersects(&mob_rect, &ver_rect, NULL) ||
        sfFloatRect_intersects(&mob_rect, &hor_rect, NULL)) {
            move_hit(s_all);
            move_explosion(s_all);
            s_all->s_infos.current_xp += temp->xp;
            update_xp(s_all);
            temp->status = -1;
        }
        temp = temp->next;
    }
}