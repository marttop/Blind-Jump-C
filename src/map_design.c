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
    for (int i = 0, j = 0; s_all->s_map.map[i] != NULL; i++, j = 0)
        for (; s_all->s_map.map[i][j] != '\0'; j++)
            if (s_all->s_map.map[i][j] == '1')
                new_map[i][j] = '1';
    return (new_map);
}

int check_grass(char **map, int i, int j)
{
    int check = 0;

    if (i - 1 == -1 || map[i - 1][j] == '1')
        check += 1000;
    if (map[i][j + 1] != '0')
        check += 100;
    if (map[i + 1] == NULL || map[i + 1][j] == '1')
        check += 10;
    if (j - 1 == -1 || map[i][j - 1] == '1')
        check += 1;

    return (check);
}

void rect_grass(tileset_t *tile, char **map, int i, int j)
{
    int check = check_grass(map, i, j);

    if (check == 1111)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){0, 0, 32, 26});
    else if (check == 111)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 1, 0, 32, 26});
    else if (check == 1011)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 2, 0, 32, 26});
    else if (check == 11)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 3, 0, 32, 26});
    else if (check == 1101)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 4, 0, 32, 26});
    else if (check == 101)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 5, 0, 32, 26});
    else if (check == 1001)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 6, 0, 32, 26});
    else if (check == 1)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 7, 0, 32, 26});
    else if (check == 1110)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 8, 0, 32, 26});
    else if (check == 110)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 9, 0, 32, 26});
    else if (check == 1010)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 10, 0, 32, 26});
    else if (check == 10)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 11, 0, 32, 26});
    else if (check == 1100)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 12, 0, 32, 26});
    else if (check == 100)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 13, 0, 32, 26});
    else if (check == 1000)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 14, 0, 32, 26});
    else if (check == 0)
        sfSprite_setTextureRect(tile->grass, (sfIntRect){32 * 15, 0, 32, 26});
}

void set_grass(tileset_t *tile, all_t *s_all, int i, int j)
{
    char **map = s_all->s_map.map;
    char **grass = s_all->s_map.grass;
   
    if (map[i][j] != '1' && grass[i][j] == '0') {
        tile->grass = sfSprite_create();
        sfSprite_setTexture(tile->grass, s_all->s_map.grass_tx, sfTrue);
        sfSprite_setPosition(tile->grass, (sfVector2f){s_all->s_map.
        tileset_pos.x, s_all->s_map.tileset_pos.y});
        rect_grass(tile, grass, i, j);
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