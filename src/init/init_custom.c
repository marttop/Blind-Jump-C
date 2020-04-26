/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_custom
*/

#include "rpg.h"
#include "utils.h"

void init_cursor(all_t *s_all)
{
    s_all->s_custom.sprite = sfSprite_create();
    s_all->s_custom.texture = s_all->s_player.hero_tx;
    sfSprite_setTexture(s_all->s_custom.sprite,
        s_all->s_custom.texture, sfTrue);
    sfSprite_setTextureRect(s_all->s_custom.sprite,
        (sfIntRect){67, 76, 5, 16});
    s_all->s_custom.pos = (sfVector2f){803, 264};
    sfSprite_setPosition(s_all->s_custom.sprite, s_all->s_custom.pos);
    sfSprite_setScale(s_all->s_custom.sprite, (sfVector2f){1, 2.5});
}

void init_custom(all_t *s_all)
{
    s_all->s_custom.select_name = sfText_create();
    s_all->s_custom.clock = sfClock_create();
    s_all->s_custom.input = sfRectangleShape_create();
    sfText_setFont(s_all->s_custom.select_name, s_all->s_game.font);
    sfText_setString(s_all->s_custom.select_name,
        "Select your character's name");
    sfText_setPosition(s_all->s_custom.select_name, (sfVector2f){750, 210});
    sfRectangleShape_setFillColor(s_all->s_custom.input,
        (sfColor){15, 15, 150, 150});
    sfRectangleShape_setPosition(s_all->s_custom.input,
        (sfVector2f){800, 260});
    sfRectangleShape_setSize(s_all->s_custom.input, (sfVector2f){350, 40});
    sfText_setPosition(s_all->s_infos.p_name_txt, (sfVector2f){805, 262});
    sfText_setString(s_all->s_infos.p_name_txt, "");
    s_all->s_custom.seconds = 0;
    s_all->s_custom.show = 1;
    init_cursor(s_all);
}

void display_cursor(all_t *s_all)
{
    if (s_all->s_custom.show == 1) {
        if (s_all->s_custom.seconds < 0.5) {
            sfRenderWindow_drawSprite(s_all->s_game.window,
                s_all->s_custom.sprite, NULL);
        } else {
            s_all->s_custom.show = 0;
        }
    }
    if (s_all->s_custom.seconds > 1) {
        sfClock_restart(s_all->s_custom.clock);
        s_all->s_custom.show = 1;
    }
}

void display_custom(all_t *s_all)
{
    if (s_all->s_game.scene == CUSTOM) {
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_custom.select_name, NULL);
        sfRenderWindow_drawRectangleShape(s_all->s_game.window,
            s_all->s_custom.input, NULL);
        display_cursor(s_all);
        sfRenderWindow_drawText(s_all->s_game.window,
            s_all->s_infos.p_name_txt, NULL);
    }
}