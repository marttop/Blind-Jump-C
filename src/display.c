/*
** EPITECH PROJECT, 2020
** Defender_v1
** File description:
** display
*/

#include "rpg.h"

void display_spawn(all_t *s_all)
{
    if (s_all->s_game.scene == SPAWN) {
        move_camera(s_all);
        sfRenderWindow_clear(s_all->s_game.window, (sfColor){12, 37, 41, 255});
        display_spawn_under(s_all);
        display_hero(s_all);
        display_spawn_over(s_all);
        sfRenderWindow_setView(s_all->s_game.window,
        sfRenderWindow_getDefaultView(s_all->s_game.window));
    }
}

void display_map(all_t *s_all)
{
    if (s_all->s_game.scene == MAP) {
        sfRenderWindow_clear(s_all->s_game.window, sfBlack);
        sfSprite_setPosition(s_all->s_map.background,
            s_all->s_effect.vignette_pos);
        move_camera(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_map.background, NULL);
        display_stars(s_all), display_tiles(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_tp.tp, NULL);
        int y = display_chests_under(s_all);
        display_mobs4(s_all), display_hearth(s_all), display_hero(s_all);
        display_chests_over(s_all, y);
        display_mobs(s_all), destroy_mobs(s_all), display_hearth2(s_all);
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_effect.tp_glow, s_all->s_effect.light_state);
        display_explosions(s_all);
    }
}

void display_chatbox(all_t *s_all)
{
    if (s_all->s_npc.talk == 1) chatbox(s_all, "pnj/tuto1");
}

void display_hud_anim(all_t *s_all)
{
    display_debug(s_all);
    move_camera(s_all);
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
        s_all->s_tp.beam, NULL);
    chest_message(s_all);
    sfRenderWindow_setView(s_all->s_game.window,
        sfRenderWindow_getDefaultView(s_all->s_game.window));
    display_minimap(s_all);
    if (s_all->s_game.scene != GAME_OVER && s_all->s_game.scene != CUSTOM
    && s_all->s_game.scene != OPT && s_all->s_game.scene != LOAD) {
        display_infos(s_all);
        display_chatbox(s_all);
        if (s_all->s_game.display_inv == 1) {
            draw_stats(s_all);
            display_inventory(s_all);
        }
    }
}

void display(all_t *s_all)
{
    sfRenderWindow_setFramerateLimit(s_all->s_game.window, s_all->s_game.fps);
    display_spawn(s_all), display_map(s_all);
    display_dead(s_all), tp_animation(s_all), display_hud_anim(s_all);
    if (s_all->s_game.pause == 1) {
        sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_game.black, NULL);
    } if (s_all->s_game.scene == MENU || s_all->s_game.pause == 1) {
        if (s_all->s_game.scene == MENU) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
            s_all->s_game.menu, NULL);
        } dispay_buttons(s_all, s_all->s_buttons);
    } display_custom(s_all), display_rgb_selector(s_all);
    if (s_all->s_game.scene == OPT) draw_options(s_all);
    display_game_over(s_all), display_load_slots(s_all);
    display_save_slots(s_all);
    if ((s_all->s_game.scene == CUSTOM || s_all->s_game.scene == LOAD)
    && s_all->s_effect.anim > 45)
        dispay_buttons(s_all, s_all->s_options.buttons);
    sfRenderWindow_display(s_all->s_game.window);
}