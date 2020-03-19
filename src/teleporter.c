/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_tp
*/

#include "rpg.h"

void init_tp(all_t *s_all)
{
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
}

int hitbox_tp(all_t *s_all)
{
    sfFloatRect shadow = sfSprite_getGlobalBounds(s_all->s_player.shadow);
    sfFloatRect tp = sfSprite_getGlobalBounds(s_all->s_tp.tp);
    if (sfFloatRect_intersects(&shadow, &tp, NULL))
        return (1);
    return (0);
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
}