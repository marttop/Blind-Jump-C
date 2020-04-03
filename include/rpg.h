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
#include <string.h>
#include <stddef.h>
#include <limits.h>

#include "utils.h"

#ifndef MY_PI
#define MY_PI (3.14159265358979323846)
#endif /* !MY_PI */

#ifndef SPAWN
#define SPAWN (1)
#endif

#ifndef MAP
#define MAP (2)
#endif

/////////////////////////////////////////
// Inventory & Equipment & Items

typedef enum weapon_type {
    SINGLE_SHOT,
    MULTI_SHOT,
} e_weapon_type;

typedef enum consumable_type {
    HP_BUFF,
    DMG_BUFF,
} e_consumable_type;

typedef enum rarity {
    COMMON,
    UNCOMMON,
    HIGH,
    LEGEND,
} e_rarity;

typedef struct weapon {
    char *name;
    int id;
    int dmg;
    float range;
    e_weapon_type type;
    sfSprite *sprite;

} t_weapon;

typedef struct consumable{
    char *name;
    int id;
    int hp;
    int dmg;
    e_consumable_type type;
    sfSprite *sprite;
} t_consumable;

typedef struct item_database{
    t_weapon weapons[12];
    t_consumable consumables[12];
} t_item_database;

typedef struct slot
{
    int id;
    int is_hover;
    int has_item;
    sfRectangleShape *shape_hover;
    sfTexture *texture_bg;
    sfTexture *texture_clck;
    sfTexture *texture_slect;
    sfSprite *sprite_bg;
    sfSprite *sprite_select;
    sfVector2f pos;
    sfIntRect rect;
    t_weapon *weapon;
    void (*on_hover)(void *d, struct slot *s, sfRenderWindow *w);
    void (*on_click)(void *d, struct slot *s, sfRenderWindow *w);
    void (*on_drag)(void *d, struct slot *s, sfRenderWindow *w);
} t_slot;

typedef struct node {
    int id;
    void *data;
    struct node *next;
    void (*dealloc)(struct node *, void *);
} t_node;

////////////////////////////////////////

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfView *camera;
    sfClock *clock;
    sfTime time;
    t_node *inv;
    sfRenderTexture *inv_tex;
    sfSprite *inv_sprite;
    sfVector2f inv_pos;
    float seconds;
    int scene;
    int debug_mode;
    int display_inv;
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
    int wall_up;
    int wall_down;
    int wall_right;
    int wall_left;
} movement_t;

typedef struct mob {
    sfSprite *mob;
    sfTexture *mob_txt;
    sfVector2f mob_pos;
    int mob_speed;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfClock *rect_clock;
    sfTime rect_time;
    float rect_seconds;
    sfIntRect rect;
    sfSprite *shadow;
    sfTexture *shadow_tx;
    sfVector2f shadow_pos;
    int move;
    char type;
    struct mob *next;
} mob_t;

typedef struct player {
    sfRectangleShape *debug;
    sfRectangleShape *debug_shadow;
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
    sfVector2f shadow_pos;
    sfSprite *gun;
    int tp;
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
    sfSprite *ship;
    sfVector2f ship_pos;
    sfRectangleShape *background;
    int open;
    sfClock *door_clock;
    sfTime door_time;
    float door_seconds;
} spawn_t;

typedef struct tileset {
    sfRectangleShape *debug;
    sfSprite *tile;
    sfSprite *top;
    sfSprite *bottom;
    sfSprite *grass;
} tileset_t;

typedef struct map {
    sfSprite *background;
    sfTexture *background_tx;
    sfVector2f background_pos;
    sfVector2f tileset_pos;
    sfTexture *tileset_tx;
    sfTexture *grass_tx;
    sfTexture *grass2_tx;
    tileset_t **tileset;
    char **map;
    char **grass;
    int x;
    int y;
} map_t;

typedef struct effect {
    sfRenderStates *light_state;
    sfSprite *light;
    sfTexture *light_tx;
    sfVector2f light_pos;
    sfRenderStates *vignette_state;
    sfSprite *vignette1;
    sfTexture *vignette1_tx;
    sfSprite *vignette2;
    sfTexture *vignette2_tx;
    sfVector2f vignette_pos;
    sfSprite *tp_glow;
    sfTexture *tp_glow_tx;
} effect_t;

typedef struct teleporter {
    sfSprite *tp;
    sfVector2f tp_pos;
    sfSprite *tp_shadow;
    sfRectangleShape *debug;
    sfRectangleShape *beam;
    sfClock *tp_clock;
    sfTime tp_time;
    sfRectangleShape *black;
    float tp_seconds;
    int alpha;
    int height;
    int anim;
    int width;
} tp_t;

typedef struct all {
    game_t s_game;
    tp_t s_tp;
    map_t s_map;
    effect_t s_effect;
    movement_t s_movement;
    player_t s_player;
    direction_t s_direction;
    spawn_t s_spawn;
    t_item_database item_db;
    struct mob *s_mob;
} all_t;

void init_all(all_t *s_all);
void init_clocks(all_t *s_all);
void game_clocks(all_t *s_all);
void display(all_t *s_all);
int game_loop(all_t *s_all);
void init_mobs(all_t *s_all);
void display_mobs(all_t *s_all);
int my_ptrlen(char **str);
void events_control(all_t *s_all);
void create_sprite(sfSprite **sprite, sfTexture **texture,
    sfVector2f pos, const char *path);
void display_hero(all_t *s_all);
void init_hero(all_t *s_all);
sfVector2f render_pos_center(all_t *s_all);
void player_movement(all_t *s_all);
void init_movement(all_t *s_all);
void generate_random_mobs(all_t *s_all);
mob_t *fill_mob(mob_t *old, char type, sfVector2f pos, all_t *s_all);
void get_movement(all_t *s_all);
void movement_up_down(all_t *s_all);
void movement_left_right(all_t *s_all);
void movement_diagonal_left_up(all_t *s_all);
void movement_diagonal_left_down(all_t *s_all);
void movement_diagonal_right_down(all_t *s_all);
void movement_diagonal_right_up(all_t *s_all);
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
sfBool is_button_released(sfEvent *e, sfMouseButton button);
sfBool is_button_pressed(sfEvent *e, sfMouseButton button);
sfBool is_key_released(sfEvent *e, sfKeyCode key);
sfBool is_key_presssed(sfEvent *e, sfKeyCode key);
void init_inventory(all_t *data);
void update_inventory(all_t *d);
void draw_inventory(all_t *d);
void add_pistol(t_node *inv);
void iterate_dealloc(t_node *n);
void display_debug(all_t *s_all);
int check_ship(all_t *s_all);
void init_effect(all_t *s_all);
void display_light_spawn(all_t *s_all);
void init_view(all_t *s_all);
void init_tp(all_t *s_all);
void tp_animation(all_t *s_all);
void door_animation(all_t *s_all);
void set_iddle_rect(all_t *s_all);
int hitbox_tp(all_t *s_all);
void init_map(all_t *s_all);
void reset_wall(all_t *s_all);
void display_map(all_t *s_all);
int loop_map_hitbox(all_t *s_all);
char **init_new_random_map(all_t *s_all);
void free_map(char **map);
char **create_map(int x, int y);
void display_tiles(all_t *s_all);
void generate_random_map(all_t *s_all);
char **init_new_random_map(all_t *s_all);
void fill_random_map(char **map);
char **copy_map(char **old_map);
void simulation_step(char **old_map, char **new_map);
void set_rect_tile(tileset_t *tile, all_t *s_all, int i, int j);
void put_tp(char **map);
void set_tp_position(all_t *s_all);
sfVector2f find_tp_spawn(all_t *s_all);
char **init_new_gass_map(all_t *s_all);
void set_grass(tileset_t *tile, all_t *s_all, int i, int j);
sfVector2i find_pos(all_t *s_all, char entity);

/* ------------ !QUEUE ------------ */

typedef struct node_queue
{
    int x;
    int y;
    struct node_queue *parent;
    struct node_queue *next;
    struct node_queue *back;
} queue_node_t;

typedef struct queue
{
    int length;
    queue_node_t *last;
    queue_node_t *first;
} queue_t;

queue_t *new_queue(void);
int is_empty_queue(queue_t *li);
queue_node_t *new_queue_node(queue_node_t *parent, int x, int y);
queue_t *push_back_queue(queue_t *li, queue_node_t *parent, int x, int y);
queue_t *pop_front_queue(queue_t *li);
queue_t *clear_queue(queue_t *li);
queue_t *dequeue_front(queue_t *li, queue_t **dequeue);
queue_t *push_new_generation(char **maze, queue_t *s_queue,
    queue_t **s_dequeue);
int check_if_found(queue_t *s_queue, sfVector2i pos_end);

/* ------------ !BREADTH_FIRST_SEARCH ------------ */

int breadth_first_search(char **maze, all_t *s_all, char start, char end);
char **breadth_first_search_entity(char **maze, all_t *s_all, int x, int y);
void format_map(char **map);

#endif /* !RPG_H_ */