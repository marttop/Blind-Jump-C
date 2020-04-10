/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_inventory(all_t *s_all)
{
    if (is_key_released(&s_all->s_game.event, sfKeyP)
    && s_all->s_game.display_inv == 1)
        add_pistol(s_all->s_game.inv);
    if (is_key_released(&s_all->s_game.event, sfKeyI))
        s_all->s_game.display_inv = !s_all->s_game.display_inv;
}

void events_control(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(s_all->s_game.window);
    }
    get_movement(s_all);
    get_aim_direction(s_all);
    shoot(s_all);
    activate_debug_mode(s_all);
    events_inventory(s_all);
    set_iddle_rect(s_all);
}