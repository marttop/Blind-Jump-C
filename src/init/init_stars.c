/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_stars
*/

#include "rpg.h"

void stars_create_texture(all_t *s_all, sfSprite *sprite,
    sfRenderTexture *render)
{
    render = sfRenderTexture_create(128 * 50, 128 * 50, 0);
    s_all->s_stars.pos = (sfVector2f){0, 0};
    for (int i = 0, j = 0; i != 50; i++, s_all->s_stars.pos.y += 128,
    s_all->s_stars.pos.x = 0) {
        for (j = 0; j != 50; j++, s_all->s_stars.pos.x += 128) {
        sfSprite_setPosition(sprite, s_all->s_stars.pos);
        sfRenderTexture_drawSprite(render, sprite, NULL);
        }
    }
    sfSprite_setTexture(sprite, sfRenderTexture_getTexture(render), sfTrue);
    s_all->s_stars.pos = (sfVector2f){-128 * 15, -128 * 15};
    sfSprite_setPosition(sprite, s_all->s_stars.pos);
}

void init_stars(all_t *s_all)
{
    s_all->s_stars.front = sfSprite_create();
    s_all->s_stars.back = sfSprite_create();
    s_all->s_stars.back_tx =
        sfTexture_createFromFile("sprites/stars_back.png", NULL);
    s_all->s_stars.front_tx =
        sfTexture_createFromFile("sprites/stars_front.png", NULL);
    sfSprite_setTexture(s_all->s_stars.back, s_all->s_stars.back_tx, sfTrue);
    sfSprite_setTexture(s_all->s_stars.front, s_all->s_stars.front_tx, sfTrue);
    stars_create_texture(s_all, s_all->s_stars.back, s_all->s_stars.render1);
    stars_create_texture(s_all, s_all->s_stars.front, s_all->s_stars.render2);
}

void move_stars(all_t *s_all, sfSprite *sprite)
{
    if (s_all->s_player.hero_seconds < 0.01 || s_all->s_player.tp == 1
    || s_all->s_game.pause == 1 || (s_all->s_player.down == 1
    && s_all->s_player.up == 1) || (s_all->s_player.left == 1
    && s_all->s_player.right == 1)) return;
    if (s_all->s_movement.left == 1 && s_all->s_movement.wall_left == 0) {
        s_all->s_stars.pos.x -= 1;
        sfSprite_setPosition(sprite, s_all->s_stars.pos);
    } if (s_all->s_movement.down == 1 && s_all->s_movement.wall_down == 0) {
        s_all->s_stars.pos.y += 1;
        sfSprite_setPosition(sprite, s_all->s_stars.pos);
    } if (s_all->s_movement.right == 1 && s_all->s_movement.wall_right == 0) {
        s_all->s_stars.pos.x += 1;
        sfSprite_setPosition(sprite, s_all->s_stars.pos);
    } if (s_all->s_movement.up == 1 && s_all->s_movement.wall_up == 0) {
        s_all->s_stars.pos.y -= 1;
        sfSprite_setPosition(sprite, s_all->s_stars.pos);
    }
}

void display_stars(all_t *s_all)
{
    move_stars(s_all, s_all->s_stars.front);
    sfRenderWindow_drawSprite(s_all->s_game.window, s_all->s_stars.back, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_stars.front, NULL);
}