/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_keyboard(all_t *s_all)
{
    if (is_key_released(&s_all->s_game.event, sfKeyI))
        s_all->s_game.display_inv = !s_all->s_game.display_inv;
    s_all->s_game.key_press = 0;
    if (sfKeyboard_isKeyPressed(sfKeyE) == 1)
        s_all->s_game.key_press = 'E';
    if (is_key_released(&s_all->s_game.event, sfKeyO))
        put_item_in_slot(s_all, 1);
    if (is_key_released(&s_all->s_game.event, sfKeyP))
        put_item_in_slot(s_all, 2);
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
    events_keyboard(s_all);
    set_iddle_rect(s_all);
}