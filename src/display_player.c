/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** display_player
*/

#include "rpg.h"

void display_weapon_down(all_t *s_all)
{
    if (s_all->s_inventory.head->is_item == 0) return;
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
    if (s_all->s_inventory.head->is_item == 0) return;
    if (s_all->s_direction.right == 1 && s_all->s_player.tp != 1) {
        sfSprite_setPosition(s_all->s_player.gun,
            (sfVector2f){s_all->s_player.hero_pos.x + 4,
            s_all->s_player.hero_pos.y + 17});
        sfSprite_setScale(s_all->s_player.gun, (sfVector2f){0.79, 0.79});
        sfSprite_setTextureRect(s_all->s_player.gun,
            (sfIntRect){687, 107, 23, 10});
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.gun, NULL);
    } if (s_all->s_direction.left == 1 && s_all->s_player.tp != 1) {
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

void display_shooting_elements(all_t *s_all)
{
    if (s_all->s_player.tp != 1) {
        if (s_all->s_player.hor == 1) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.hor_shoot, NULL);
        }
        if (s_all->s_player.ver == 1) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.ver_shoot, NULL);
        }
        display_weapon_left_right(s_all);
        if (s_all->s_player.hit == 1) display_hit(s_all);
    }
}

void display_hero(all_t *s_all)
{
    rect_hero(s_all);
    if (s_all->s_player.refresh_sec > 0.1 && s_all->s_mob != NULL &&
    s_all->s_game.pause == 0)
        refresh_path(s_all);
    sfSprite_setPosition(s_all->s_player.shadow,
    (sfVector2f){s_all->s_player.hero_pos.x + 3,
    s_all->s_player.hero_pos.y + 26});
    display_shooting_elements(s_all);
    if (s_all->s_tp.anim != 2) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.shadow, NULL);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_player.hero, NULL);
    } if (s_all->s_player.tp != 1) display_weapon_down(s_all);
    shooting_control(s_all), player_immunity(s_all);
}