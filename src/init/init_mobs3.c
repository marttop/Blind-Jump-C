/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs3
*/

#include "rpg.h"

void display_mobs3(mob_t *temp, all_t *s_all)
{
    if (temp->type == 'A' && s_all->s_game.pause == 0) {
        if (temp->bullet_travel >= 100) {
            sfSprite_setPosition(temp->bullet, (sfVector2f)
            {temp->mob_pos.x - 4, temp->mob_pos.y- 8}), temp->hit = 0;
            temp->check_shoot = 0, temp->bullet_travel = 0;
        } if (temp->aggro == 1
        && calcul_mob_magnitude(temp, s_all->s_player.shadow) <= 220) {
            temp->shoot = 1;
        } else {
            sfSprite_setPosition(temp->bullet, (sfVector2f)
            {temp->mob_pos.x - 4, temp->mob_pos.y - 8}), temp->shoot = 0;
        } roballs_shoot(temp, s_all);
    } if (temp->check_shoot == 0 || temp->hit == 1
    || calcul_mob_magnitude(temp, s_all->s_player.shadow) > 220) return;
        sfRenderWindow_drawSprite(s_all->s_game.window, temp->bullet, NULL);
}