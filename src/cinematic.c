/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** cinematic
*/

#include "rpg.h"

void cinematic2(all_t *s_all)
{
    static int i = 0;
    if (s_all->s_cine.script == 2 && s_all->s_inventory.head->is_item == 1) {
        s_all->s_cine.script = 3, s_all->s_chatbox.buff[0] = '\0';
        s_all->s_chatbox.op = 0, s_all->s_chatbox.idx = 0;
        s_all->s_chatbox.car = 0;
    }
    if (s_all->s_cine.script == 5 && i == 0) {
        i++;
        s_all->s_chatbox.buff[0] = '\0';
        s_all->s_chatbox.op = 0;
        s_all->s_chatbox.idx = 0;
        s_all->s_chatbox.car = 0;
    }
    if (s_all->s_cine.script > 1 && s_all->s_game.scene == SPAWN
    && s_all->s_chest->status == 0)
        s_all->s_chest->status = 1;
}

void cinematic1(all_t *s_all)
{
    static int check1 = 0, check2 = 0, check3 = 0, check4 = 0;
    if (s_all->s_cine.seconds < 0.01) return;
    if (s_all->s_cine.script == 0 && s_all->s_cine.tuto == 1) {
        s_all->s_cine.move = 2, s_all->s_npc.talk = 1, s_all->s_game.chat = 1;
        if (s_all->s_movement.down == 1 && check1 == 0)
            check1 = 1, s_all->s_cine.count += 1;
        if (s_all->s_movement.up == 1 && check2 == 0)
            check2 = 1, s_all->s_cine.count += 1;
        if (s_all->s_movement.left == 1 && check3 == 0)
            check3 = 1, s_all->s_cine.count += 1;
        if (s_all->s_movement.right == 1 && check4 == 0)
            check4 = 1, s_all->s_cine.count += 1;
        if (s_all->s_cine.count == 4) {
            s_all->s_cine.script = 1, s_all->s_chatbox.buff[0] = '\0';
            s_all->s_chatbox.op = 0, s_all->s_chatbox.idx = 0;
            s_all->s_chatbox.car = 0;
        }
    } cinematic2(s_all);
    sfClock_restart(s_all->s_cine.clock);
}