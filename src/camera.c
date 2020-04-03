/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** camera
*/

#include "rpg.h"

void init_view(all_t *s_all)
{
    s_all->s_game.camera =
        sfView_copy(sfRenderWindow_getView(s_all->s_game.window));
    sfView_zoom(s_all->s_game.camera, 0.4);
    sfView_setCenter(s_all->s_game.camera,
        (sfVector2f){s_all->s_player.hero_pos.x - 10,
        s_all->s_player.hero_pos.y - 15});
    sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
    s_all->s_effect.vignette_pos = (sfVector2f){0, 0};
    create_sprite(&s_all->s_effect.vignette1, &s_all->s_effect.vignette1_tx,
        s_all->s_effect.vignette_pos, "sprites/vignette_shadow.png");
    create_sprite(&s_all->s_effect.vignette2, &s_all->s_effect.vignette2_tx,
        s_all->s_effect.vignette_pos, "sprites/vignette_mask.png");
    sfSprite_setScale(s_all->s_effect.vignette1, (sfVector2f){1.71, 0.93});
    sfSprite_setScale(s_all->s_effect.vignette2, (sfVector2f){1.71, 0.93});
}

void move_camera2(all_t *s_all)
{
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_tp.black, NULL);
}

void move_camera(all_t *s_all)
{
    sfView_setCenter(s_all->s_game.camera,
        (sfVector2f){s_all->s_player.hero_pos.x + 10,
        s_all->s_player.hero_pos.y + 15});
    sfRenderWindow_setView(s_all->s_game.window, s_all->s_game.camera);
    s_all->s_effect.vignette_pos =
        (sfVector2f){s_all->s_player.hero_pos.x - 375,
        s_all->s_player.hero_pos.y - 194};
    sfSprite_setPosition(s_all->s_effect.vignette1,
        s_all->s_effect.vignette_pos);
    sfSprite_setPosition(s_all->s_effect.vignette2,
        s_all->s_effect.vignette_pos);
    sfRectangleShape_setPosition(s_all->s_tp.black,
        (sfVector2f){s_all->s_player.hero_pos.x - 374,
        s_all->s_player.hero_pos.y - 193});
    if (s_all->s_game.scene == SPAWN)
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_effect.vignette1, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
        s_all->s_effect.vignette2, s_all->s_effect.vignette_state);
    move_camera2(s_all);
}