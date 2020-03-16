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
#include "time.h"

#ifndef MY_PI
#define MY_PI (3.14159265358979323846)
#endif /* !MY_PI */

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    sfTime time;
    float seconds;
    int scene;
} game_t;

typedef struct all {
    game_t s_game;
} all_t;

void init_all(all_t *s_all);
void init_clocks(all_t *s_all);
void game_clocks(all_t *s_all);
void display(all_t *s_all);
int game_loop(all_t *s_all);
void events_control(all_t *s_all);

#endif /* !RPG_H_ */
