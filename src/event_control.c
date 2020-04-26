/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_inventory(all_t *s_all)
{
    if (is_key_released(&s_all->s_game.event, sfKeyI))
        s_all->s_game.display_inv = !s_all->s_game.display_inv;
    s_all->s_game.key_press = 0;
    if (sfKeyboard_isKeyPressed(sfKeyE) == 1)
        s_all->s_game.key_press = 'E';
}

void events_control(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtClosed ||
        sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(s_all->s_game.window);
    }
    if (s_all->s_game.scene != CUSTOM && s_all->s_game.scene != GAME_OVER) {
        get_movement(s_all);
        get_aim_direction(s_all);
        shoot(s_all);
        activate_debug_mode(s_all);
        if (is_key_released(&s_all->s_game.event, sfKeyP))
            add_weapon(s_all->s_game.inventory.inv, create_pistol());
        if (is_key_released(&s_all->s_game.event, sfKeyO))
            add_weapon(s_all->s_game.inventory.inv, create_scorpion());
        events_inventory(s_all);
        set_iddle_rect(s_all);
    }
    get_text_entered(s_all);
}