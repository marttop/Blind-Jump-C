/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** get_player_name
*/

#include "rpg.h"
#include "utils.h"

void my_getchar(sfUint32 c, all_t *s_all)
{
    int i = my_strlen(s_all->s_infos.p_name);
    if (c < 97 || c > 122) return;
    c = (char){c};
    s_all->s_infos.p_name[i] = c;
    i++;
    s_all->s_infos.p_name[i] = '\0';
    sfText_setString(s_all->s_infos.p_name_txt, s_all->s_infos.p_name);
}

void my_popchar(all_t *s_all)
{
    int i = my_strlen(s_all->s_infos.p_name) - 1;
    if (i < 0) return;
    s_all->s_infos.p_name[i] = '\0';
    sfText_setString(s_all->s_infos.p_name_txt, s_all->s_infos.p_name);
}

void get_text_entered(all_t *s_all)
{
    if (s_all->s_game.scene == CUSTOM && s_all->s_effect.anim > 45) {
        if (s_all->s_game.event.type == sfEvtTextEntered &&
        my_strlen(s_all->s_infos.p_name) < 20) {
            my_getchar(s_all->s_game.event.text.unicode, s_all);
        }
        else if ((sfKeyboard_isKeyPressed(sfKeyBack) ||
        sfKeyboard_isKeyPressed(sfKeyDelete)) &&
        my_strlen(s_all->s_infos.p_name) >= 0) {
            my_popchar(s_all);
        }
        else if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            sfText_setPosition(s_all->s_infos.p_name_txt,
                (sfVector2f){725, 885});
            s_all->s_game.scene = SPAWN;
            sfRectangleShape_setFillColor(s_all->s_tp.black,
                (sfColor){0, 0, 0, 0});
        }
    }
}