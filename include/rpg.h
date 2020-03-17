/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rpg
*/

#ifndef RPG_H_
#define RPG_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Types.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Transform.h>
#include <SFML/System/Vector2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>

#include "utils.h"

#ifndef MY_PI
#define MY_PI (3.14159265358979323846)
#endif /* !MY_PI */

#ifndef SPAWN
#define SPAWN (1)
#endif

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfView *camera;
    sfClock *clock;
    sfTime time;
    float seconds;
    int scene;
    int debug_mode;
} game_t;

typedef struct direction {
    int up;
    int down;
    int left;
    int right;
} direction_t;

typedef struct movement {
    int up;
    int down;
    int left;
    int right;
} movement_t;

typedef struct player {
    sfRectangleShape *debug;
    sfSprite *hero;
    sfTexture *hero_tx;
    sfVector2f hero_pos;
    int hero_speed;
    sfClock *hero_clock;
    sfTime hero_time;
    float hero_seconds;
    sfClock *rect_clock;
    sfTime rect_time;
    float rect_seconds;
    sfIntRect hero_rect;
    sfSprite *shadow;
    sfTexture *shadow_tx;
} player_t;

typedef struct spawn {
    sfSprite *ground;
    sfTexture *ground_tx;
    sfVector2f ground_pos;
    sfSprite *mask;
    sfTexture *mask_tx;
    sfVector2f mask_pos;
    sfSprite *door;
    sfTexture *door_tx;
    sfVector2f door_pos;
} spawn_t;

typedef struct all {
    game_t s_game;
    movement_t s_movement;
    player_t s_player;
    direction_t s_direction;
    spawn_t s_spawn;
} all_t;

void init_all(all_t *s_all);
void init_clocks(all_t *s_all);
void game_clocks(all_t *s_all);
void display(all_t *s_all);
int game_loop(all_t *s_all);
void events_control(all_t *s_all);
void create_sprite(sfSprite **sprite, sfTexture **texture,
    sfVector2f pos, const char *path);
void display_hero(all_t *s_all);
void init_hero(all_t *s_all);
sfVector2f render_pos_center(all_t *s_all);
void player_movement(all_t *s_all);
void init_movement(all_t *s_all);
void get_movement(all_t *s_all);
void movement_up_down(all_t *s_all);
void movement_left_right(all_t *s_all);
void movement_diagonal_left(all_t *s_all);
void movement_diagonal_right(all_t *s_all);
void rect_hero(all_t *s_all);
sfRectangleShape *init_hitbox_debug(sfRectangleShape *rectangle, sfVector2f pos,
    sfSprite *sprite);
void display_hitbox_debug(all_t *s_all, sfRectangleShape *rectangle,
    sfSprite *sprite);
void set_position_debug(sfRectangleShape *rectangle, sfVector2f pos);
void activate_debug_mode(all_t *s_all);
void init_direction(all_t *s_all);
void get_aim_direction(all_t *s_all);
int rect_down(all_t *s_all, int *check, int *i);
int rect_up(all_t *s_all, int *check, int *i);
int rect_left(all_t *s_all, int *check, int *i);
int rect_right(all_t *s_all, int *check, int *i);
int rect_down_condition(all_t *s_all, int *check, int *i);
int rect_up_condition(all_t *s_all, int *check, int *i);
int rect_left_condition(all_t *s_all, int *check, int *i);
int rect_right_condition(all_t *s_all, int *check, int *i);
void init_spawn(all_t *s_all);
void display_spawn_under(all_t *s_all);
void display_spawn_over(all_t *s_all);
void move_camera(all_t *s_all);
int check_borders(all_t *s_all);
int check_middle_wall(all_t *s_all);

#endif /* !RPG_H_ */
