/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player
*/

#include "rpg.h"

void display_weapon_down(all_t *s_all)
{
    if (s_all->s_direction.down == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 6,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){742, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, NULL);
    }
}

void display_weapon_left_right(all_t *s_all)
{
    if (s_all->s_direction.right == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 4,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){687, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, NULL);
    }
    if (s_all->s_direction.left == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 16,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){-0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){687, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, NULL);
    }
}

void display_hero(all_t *s_all)
{
    tp_animation(s_all);
    rect_hero(s_all);
    sfSprite_setPosition(s_all->s_player.shadow,
    (sfVector2f){s_all->s_player.hero_pos.x + 3,
    s_all->s_player.hero_pos.y + 26});
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.shadow, NULL);
    display_weapon_left_right(s_all);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_player.hero, NULL);
    display_weapon_down(s_all);
}