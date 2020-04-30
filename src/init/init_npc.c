/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_npc
*/

#include "rpg.h"

void init_computer(all_t *s_all)
{
    s_all->s_npc.computer = sfSprite_create();
    s_all->s_npc.screen = sfSprite_create();
    sfSprite_setTexture(s_all->s_npc.computer,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setTexture(s_all->s_npc.screen,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setTextureRect(s_all->s_npc.computer,
        (sfIntRect){0, 133, 21, 38});
    sfSprite_setTextureRect(s_all->s_npc.screen, (sfIntRect){21, 133, 19, 10});
    s_all->s_npc.pos_pc = (sfVector2f){s_all->s_spawn.ship_pos.x - 60,
        s_all->s_spawn.ship_pos.y - 79};
    sfSprite_setPosition(s_all->s_npc.computer, s_all->s_npc.pos_pc);
    sfSprite_setPosition(s_all->s_npc.screen,
        (sfVector2f){s_all->s_npc.pos_pc.x + 1, s_all->s_npc.pos_pc.y + 2});
}

void display_computer(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_npc.computer, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_npc.screen, NULL);
}