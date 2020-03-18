/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_spawn
*/

#include "rpg.h"

void init_spawn2(all_t *s_all)
{
    s_all->s_spawn.door_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_spawn.door, &s_all->s_spawn.door_tx,
        s_all->s_spawn.door_pos, "sprites/spawn_wall.png");
    sfSprite_setOrigin(s_all->s_spawn.door,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_spawn.door).width / 2,
        sfSprite_getGlobalBounds(s_all->s_spawn.door).height / 2});
    sfSprite_setPosition(s_all->s_spawn.door,
        (sfVector2f){s_all->s_spawn.door_pos.x += 305,
        s_all->s_spawn.door_pos.y += 48});
    sfSprite_setTextureRect(s_all->s_spawn.door,
        (sfIntRect){600, 0, 200, 100});
}

void init_spawn(all_t *s_all)
{
    s_all->s_spawn.ground_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_spawn.ground, &s_all->s_spawn.ground_tx,
        s_all->s_spawn.ground_pos, "sprites/spawn_ground.png");
    sfSprite_setOrigin(s_all->s_spawn.ground,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_spawn.ground).width / 2,
        sfSprite_getGlobalBounds(s_all->s_spawn.ground).height / 2});
    s_all->s_spawn.mask_pos = render_pos_center(s_all);
    create_sprite(&s_all->s_spawn.mask, &s_all->s_spawn.mask_tx,
        s_all->s_spawn.mask_pos, "sprites/spawn_mask.png");
    sfSprite_setOrigin(s_all->s_spawn.mask,
        (sfVector2f){sfSprite_getGlobalBounds(s_all->s_spawn.mask).width / 2,
        sfSprite_getGlobalBounds(s_all->s_spawn.mask).height / 2});
    init_spawn2(s_all);
}

void display_spawn_under(all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.ground, NULL);
    if (s_all->s_player.hero_pos.y > 580)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.door, NULL);
}

void display_spawn_over(all_t *s_all)
{
    if (s_all->s_player.hero_pos.y <= 580)
        sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.door, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_spawn.mask, NULL);
}