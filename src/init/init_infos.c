/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_infos
*/

#include "rpg.h"
#include "utils.h"

void init_xp_bar(all_t *s_all)
{
    s_all->s_infos.xp = sfRectangleShape_create();
    s_all->s_infos.xp_base = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_infos.xp,
        (sfColor){255, 150, 50, 255});
    sfRectangleShape_setFillColor(s_all->s_infos.xp_base,
        (sfColor){35, 35, 35, 255});
    sfRectangleShape_setPosition(s_all->s_infos.xp,
        (sfVector2f){60, 950});
    sfRectangleShape_setPosition(s_all->s_infos.xp_base,
        (sfVector2f){60, 950});
    sfRectangleShape_setSize(s_all->s_infos.xp, (sfVector2f){3, 20});
    sfRectangleShape_setSize(s_all->s_infos.xp_base, (sfVector2f){450, 20});
}

void init_infos(all_t *s_all)
{
    init_xp_bar(s_all);
    s_all->s_infos.p_name_txt = sfText_create();
    s_all->s_infos.lvl_txt = sfText_create();
    s_all->s_infos.xp_txt = sfText_create();
    sfText_setFont(s_all->s_infos.p_name_txt, s_all->s_game.font);
    sfText_setPosition(s_all->s_infos.p_name_txt, (sfVector2f){60, 905});
    sfText_setString(s_all->s_infos.p_name_txt, "Verge");
    sfText_setFont(s_all->s_infos.lvl_txt, s_all->s_game.font);
    sfText_setPosition(s_all->s_infos.lvl_txt, (sfVector2f){395, 905});
    sfText_setString(s_all->s_infos.lvl_txt, "Level 1");
    sfText_setFont(s_all->s_infos.xp_txt, s_all->s_game.font);
    s_all->s_infos.current_xp = 0, s_all->s_infos.max_xp = 100;
    s_all->s_infos.str_xp = malloc(25);
    s_all->s_infos.str_xp[0] = '\0';
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.current_xp));
    my_strcat(s_all->s_infos.str_xp, "/");
    my_strcat(s_all->s_infos.str_xp, strnbr(s_all->s_infos.max_xp));
    sfText_setString(s_all->s_infos.xp_txt, s_all->s_infos.str_xp);
    sfText_setPosition(s_all->s_infos.xp_txt, (sfVector2f){240, 948});
    sfText_setCharacterSize(s_all->s_infos.xp_txt, 20);
}

void display_infos(all_t *s_all)
{
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_infos.xp_base, NULL);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_infos.xp, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.p_name_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.lvl_txt, NULL);
    sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_infos.xp_txt, NULL);
}