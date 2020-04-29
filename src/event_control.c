/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_keyboard(all_t *s_all)
{
    if (s_all->s_game.pause == 1) return;
    if (is_key_released(&s_all->s_game.event, sfKeyI))
        s_all->s_game.display_inv = !s_all->s_game.display_inv;
    s_all->s_game.key_press = 0;
    if (sfKeyboard_isKeyPressed(sfKeyE) == 1)
        s_all->s_game.key_press = 'E';
    if (is_key_released(&s_all->s_game.event, sfKeyO))
        put_item_in_slot(s_all, 1);
    if (is_key_released(&s_all->s_game.event, sfKeyP))
        put_item_in_slot(s_all, 2);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == 1) {
        s_all->s_player.space = 1;
        s_all->s_game.event.type = 0;
    } else if (is_key_released(&s_all->s_game.event, sfKeySpace) == 1) {
        s_all->s_player.space = 0;
        s_all->s_game.event.type = 0;
    }
}

void pause_game(all_t *s_all)
{
    if (s_all->s_game.pause == 0 &&
    (s_all->s_game.scene == SPAWN || s_all->s_game.scene == MAP)) {
        if (is_key_released(&s_all->s_game.event, sfKeyEscape)) {
            s_all->s_game.pause = 1;
        }
    }
    else if (s_all->s_game.pause == 1 &&
    (s_all->s_game.scene == SPAWN || s_all->s_game.scene == MAP)) {
        if (is_key_released(&s_all->s_game.event, sfKeyF)) {
            s_all->s_game.pause = 0;
        }
    }
}

void events_control(all_t *s_all)
{
    pause_game(s_all);
    if (s_all->s_game.event.type == sfEvtClosed) {
        sfRenderWindow_close(s_all->s_game.window);
    }
    if (s_all->s_game.scene == MENU || s_all->s_game.scene == GAME_OVER
    || s_all->s_game.scene == CUSTOM || s_all->s_game.scene == OPT) {
        if (is_key_released(&s_all->s_game.event, sfKeyZ)
        && s_all->s_game.scene == MENU)
            s_all->s_game.scene = CUSTOM;
        if (s_all->s_game.scene == CUSTOM)
            get_text_entered(s_all);
        return;
    }
    get_movement(s_all), get_aim_direction(s_all),
    activate_debug_mode(s_all), events_keyboard(s_all);
    set_iddle_rect(s_all);
}