/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** event_controll
*/

#include "rpg.h"

void events_control(all_t *s_all)
{
    if (s_all->s_game.event.type == sfEvtClosed) {
        sfRenderWindow_close(s_all->s_game.window);
    }
}