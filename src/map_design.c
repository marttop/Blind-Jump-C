/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** map_design
*/

#include "rpg.h"

void set_top_tile(tileset_t *tile, all_t *s_all, int i, int j)
{
    char **map = s_all->s_map.map;
    if (i - 1 < 0 || map[i - 1][j] == '1') {
        tile->top = sfSprite_create();
        sfSprite_setTexture(tile->top, s_all->s_map.tileset_tx, sfTrue);
        sfSprite_setPosition(tile->top, (sfVector2f){s_all->s_map.
        tileset_pos.x, s_all->s_map.tileset_pos.y - 26});
        sfSprite_setTextureRect(tile->top, (sfIntRect){128, 0, 32, 26});
    }
    else
        tile->top = NULL;
}

void set_bottom_tile(tileset_t *tile, all_t *s_all, int i, int j)
{
    int random = rand() % 100;
    char **map = s_all->s_map.map;
    if (map[i + 1] == NULL || map[i + 1][j] == '1') {
        tile->bottom = sfSprite_create();
        sfSprite_setTexture(tile->bottom, s_all->s_map.tileset_tx, sfTrue);
        sfSprite_setPosition(tile->bottom, (sfVector2f){s_all->s_map.
        tileset_pos.x, s_all->s_map.tileset_pos.y + 26});
        if (random <= 33)
            sfSprite_setTextureRect(tile->bottom, (sfIntRect){289, 0, 32, 26});
        else if (random > 33 && random <= 66)
            sfSprite_setTextureRect(tile->bottom, (sfIntRect){322, 0, 32, 26});
        else
            sfSprite_setTextureRect(tile->bottom, (sfIntRect){96, 0, 32, 26});
    }
    else
        tile->bottom = NULL;
}

char **init_new_gass_map(all_t *s_all)
{
    static int i = 0;
    if (i == 0)
        s_all->s_map.grass = create_map(s_all->s_map.x, s_all->s_map.y);
    else {
        free(s_all->s_map.grass);
        s_all->s_map.grass = create_map(s_all->s_map.x, s_all->s_map.y);
    }  
    char **new_map = copy_map(s_all->s_map.grass);
    i = 1;

    fill_random_map(s_all->s_map.grass);

    for (int i = 0; i != 10; i++)
        simulation_step(s_all->s_map.grass, new_map);

    free_map(s_all->s_map.grass);

    return (new_map);
}

void set_grass(tileset_t *tile, all_t *s_all, int i, int j)
{
    char **map = s_all->s_map.map;
    char **grass = s_all->s_map.grass;
   
    if (map[i][j] == '0' && grass[i][j] == '0') {
        tile->grass= sfSprite_create();
        sfSprite_setTexture(tile->grass, s_all->s_map.tileset_tx, sfTrue);
        sfSprite_setPosition(tile->grass, (sfVector2f){s_all->s_map.
        tileset_pos.x, s_all->s_map.tileset_pos.y + 26});
        sfSprite_setTextureRect(tile->grass, (sfIntRect){0, 0, 32, 26});
    }
    else
        tile->grass = NULL;
}

void set_rect_tile(tileset_t *tile, all_t *s_all, int i, int j)
{
    int random = rand() % 100;
    char **map = s_all->s_map.map;
    set_bottom_tile(tile, s_all, i, j);
    set_top_tile(tile, s_all, i, j);
    set_grass(tile, s_all, i, j);
    if (i == 0 || j == 0 || map[i + 1] == NULL || map[i][j + 1] == '\0' ||
    map[i - 1][j] == '1' || map[i + 1][j] == '1' || map[i][j + 1] == '1'
    || map[i][j - 1] == '1') {
        if (random >= 85)
            sfSprite_setTextureRect(tile->tile, (sfIntRect){256, 0, 32, 26});
        else sfSprite_setTextureRect(tile->tile, (sfIntRect){0, 0, 32, 26});
        return;
    }
    if (random >= 70)
        sfSprite_setTextureRect(tile->tile, (sfIntRect){64, 0, 32, 26});
    else
        sfSprite_setTextureRect(tile->tile, (sfIntRect){33, 0, 32, 26});
}