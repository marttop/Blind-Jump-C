/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_tp
*/

#include "rpg.h"

void init_tp2(all_t *s_all)
{
    s_all->s_tp.beam = sfRectangleShape_create();
    sfRectangleShape_setFillColor(s_all->s_tp.beam,
        (sfColor){117, 253, 234, 0});
    sfRectangleShape_setSize(s_all->s_tp.beam, (sfVector2f){2, 50});
    sfRectangleShape_setOrigin(s_all->s_tp.beam, (sfVector2f){1, 50});
    sfRectangleShape_setPosition(s_all->s_tp.beam,
        (sfVector2f){s_all->s_tp.tp_pos.x + 16, s_all->s_tp.tp_pos.y + 19});
    s_all->s_tp.alpha = 0;
    s_all->s_tp.height = 0;
    s_all->s_tp.anim = 0;
    s_all->s_tp.width = 2;
}

void init_tp(all_t *s_all)
{
    s_all->s_tp.tp_clock = sfClock_create();
    s_all->s_tp.tp = sfSprite_create();
    sfSprite_setTexture(s_all->s_tp.tp, s_all->s_player.hero_tx, sfTrue);
    s_all->s_tp.tp_pos = (sfVector2f){935, 322};
    sfSprite_setTextureRect(s_all->s_tp.tp, (sfIntRect){391, 224, 32, 30});
    sfSprite_setPosition(s_all->s_tp.tp, s_all->s_tp.tp_pos);
    s_all->s_tp.tp_shadow = sfSprite_create();
    sfSprite_setTexture(s_all->s_tp.tp_shadow,
        s_all->s_player.hero_tx, sfTrue);
    sfSprite_setTextureRect(s_all->s_tp.tp_shadow,
        (sfIntRect){175, 196, 32, 32});
    sfSprite_setPosition(s_all->s_tp.tp_shadow,
        (sfVector2f){s_all->s_tp.tp_pos.x, s_all->s_tp.tp_pos.y + 7});
    s_all->s_tp.debug = init_hitbox_debug(s_all->s_tp.debug,
        s_all->s_tp.tp_pos, s_all->s_tp.tp);
    init_tp2(s_all);

}

int hitbox_tp(all_t *s_all)
{
    sfFloatRect shadow = sfSprite_getGlobalBounds(s_all->s_player.shadow);
    sfFloatRect tp = sfSprite_getGlobalBounds(s_all->s_tp.tp);
    if (sfFloatRect_intersects(&shadow, &tp, NULL))
        return (1);
    return (0);
}

void tp_animation2(all_t *s_all)
{
    if (s_all->s_player.tp == 1 && s_all->s_tp.tp_seconds >= 0.01) {
        if (s_all->s_tp.anim == 0 && s_all->s_tp.alpha < 240) {
            s_all->s_tp.alpha += 10;
            s_all->s_tp.height += 10;
            sfRectangleShape_setOrigin(s_all->s_tp.beam,
                (sfVector2f){1, s_all->s_tp.height});
            sfRectangleShape_setFillColor(s_all->s_tp.beam,
                (sfColor){117, 253, 234, s_all->s_tp.alpha});
        } if (s_all->s_tp.anim == 0 && s_all->s_tp.alpha >= 240) {
            s_all->s_tp.anim = 1;
            sfRectangleShape_setFillColor(s_all->s_tp.beam,
                (sfColor){117, 253, 234, 255});
        }
        if (s_all->s_tp.anim == 1 && s_all->s_tp.width < 20) {
            s_all->s_tp.width += 2;
            sfRectangleShape_setOrigin(s_all->s_tp.beam,
                (sfVector2f){s_all->s_tp.width / 2, s_all->s_tp.height});
        } sfRectangleShape_setSize(s_all->s_tp.beam,
            (sfVector2f){s_all->s_tp.width, s_all->s_tp.height});
    }
}

void tp_animation(all_t *s_all)
{
    if (hitbox_tp(s_all) == 1 && s_all->s_player.tp == 0) {
        s_all->s_player.tp = 1;
        s_all->s_player.hero_rect.left = 406;
        s_all->s_player.hero_rect.top = 109;
        s_all->s_player.hero_rect.height = 31;
        sfSprite_setTextureRect(s_all->s_player.hero,
            s_all->s_player.hero_rect);
        s_all->s_player.hero_pos = (sfVector2f){s_all->s_tp.tp_pos.x + 6,
            s_all->s_tp.tp_pos.y - 17};
        sfSprite_setPosition(s_all->s_player.hero, s_all->s_player.hero_pos);
        sfRectangleShape_setPosition(s_all->s_player.debug,
            s_all->s_player.hero_pos);
    }
    tp_animation2(s_all);
}