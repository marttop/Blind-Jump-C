/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** update_infos
*/

#include "rpg.h"
#include "utils.h"

void level_up(all_t *s_all)
{
    sfSound_play(s_all->s_sounds.lvl);
    s_all->s_infos.current_xp -= s_all->s_infos.max_xp;
    s_all->s_infos.max_xp *= 2;
    if (s_all->s_infos.str_xp != NULL) free(s_all->s_infos.str_xp);
    if (s_all->s_infos.str_level != NULL) free(s_all->s_infos.str_level);
    s_all->s_infos.level += 1, s_all->s_infos.dmg += 50;
    s_all->s_infos.str_xp = malloc(25);
    s_all->s_infos.str_level = malloc(20);
    s_all->s_infos.str_xp[0] = '\0', s_all->s_infos.str_level[0] = '\0';
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.current_xp));
    my_strcat(s_all->s_infos.str_xp, "/");
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.max_xp));
    my_strcat(s_all->s_infos.str_level, "Level ");
    my_strcat(s_all->s_infos.str_level, strnbr(s_all->s_infos.level));
    sfText_setString(s_all->s_infos.xp_txt, s_all->s_infos.str_xp);
    sfText_setString(s_all->s_infos.lvl_txt, s_all->s_infos.str_level);
    float xp = 450.0 / s_all->s_infos.max_xp * s_all->s_infos.current_xp;
    sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){xp, 20});
    if (s_all->s_infos.current_xp == 0)
        sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){3, 20});
}

void update_xp(all_t *s_all)
{
    if (s_all->s_infos.current_xp > s_all->s_infos.max_xp) {
        level_up(s_all);
        return;
    }
    if (s_all->s_infos.str_xp != NULL)
        free(s_all->s_infos.str_xp);
    s_all->s_infos.str_xp = malloc(25);
    s_all->s_infos.str_xp[0] = '\0';
    float xp = 450.0 / s_all->s_infos.max_xp * s_all->s_infos.current_xp;
    sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){xp, 20});
    if (s_all->s_infos.current_xp == 0)
        sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){3, 20});
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.current_xp));
    my_strcat(s_all->s_infos.str_xp, "/");
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.max_xp));
    sfText_setString(s_all->s_infos.xp_txt, s_all->s_infos.str_xp);
}