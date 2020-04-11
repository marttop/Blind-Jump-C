/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chest_hitbox
*/

#include "rpg.h"

void chest_hitbox3(all_t *s_all, int *direction, int *check)
{
    if (direction[0] == 1 && s_all->s_movement.up == 1) {
        s_all->s_movement.wall_up = 1;
        *check = 1;
    }

    if (direction[1] == 1 && s_all->s_movement.right == 1) {
        s_all->s_movement.wall_right = 1;
        *check = 1;
    }
}

void chest_hitbox2(all_t *s_all, int *direction, int *check)
{
    if (direction[2] == 1 && s_all->s_movement.down == 1) {
        s_all->s_movement.wall_down = 1;
        *check = 1;
    }
    if (direction[3] == 1 && s_all->s_movement.left == 1) {
        s_all->s_movement.wall_left = 1;
        *check = 1;
    }
    chest_hitbox3(s_all, direction, check);
}

int chest_hitbox(all_t *s_all, sfFloatRect shadow_bounds)
{
    int check = 0;
    int direction[4] = {0, 0, 0, 0};
    chest_t *tmp = s_all->s_chest;
    sfFloatRect chest_bounds;
    for (; tmp != NULL; tmp = tmp->next) {
        chest_bounds = sfSprite_getGlobalBounds(tmp->sprite);
        chest_bounds.top += chest_bounds.height / 2;
        chest_bounds.height /= 2;
        direction[0] += sfFloatRect_contains(&chest_bounds, shadow_bounds.left +
        shadow_bounds.width / 2, shadow_bounds.top);
        direction[1] += sfFloatRect_contains(&chest_bounds, shadow_bounds.left +
        shadow_bounds.width, shadow_bounds.top + shadow_bounds.height / 2);
        direction[2] += sfFloatRect_contains(&chest_bounds, shadow_bounds.left +
        shadow_bounds.width / 2, shadow_bounds.top + shadow_bounds.height);
        direction[3] += sfFloatRect_contains(&chest_bounds, shadow_bounds.left,
        shadow_bounds.top + shadow_bounds.height / 2);
    } chest_hitbox2(s_all, direction, &check);
    if (check != 0)
        return (1);
    return (0);
}

int loop_chest_hitbox(all_t *s_all)
{
    if (s_all->s_game.scene != MAP)
        return (0);

    sfFloatRect shadow_bounds =
        sfSprite_getGlobalBounds(s_all->s_player.shadow);

    if (chest_hitbox(s_all, shadow_bounds) == 1)
        return (1);
    return (0);
}
