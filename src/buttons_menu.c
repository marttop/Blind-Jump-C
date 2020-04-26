/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttons_menu
*/

#include "rpg.h"

char **tab_buttons(void)
{
    char **tab = malloc(sizeof(char *) * 4);
    tab[0] = "sprites/buttons/quit1.png";
    tab[1] = "sprites/buttons/quit2.png";
    tab[2] = "sprites/buttons/opts1.png";
    tab[3] = "sprites/buttons/opts2.png";
    return (tab);
}

void init_buttons(all_t *s_all)
{
    char **tab = tab_buttons();
    m_buttons_t *old = NULL;
    sfVector2f pos = {100, 940};
    for (int i = 0, id = 0; id != 2; i += 2, pos.x += 140, id++) {
        m_buttons_t *tmp = malloc(sizeof(m_buttons_t));
        tmp->sprite = sfSprite_create();
        tmp->button1 = sfTexture_createFromFile(tab[i], NULL);
        tmp->button2 = sfTexture_createFromFile(tab[i + 1], NULL);
        sfSprite_setTexture(tmp->sprite, tmp->button1, sfTrue);
        sfSprite_setPosition(tmp->sprite, pos);
        tmp->position = pos;
        tmp->id = id;
        tmp->next = old;
        old = tmp;
    }
    s_all->s_buttons = old;
    free(tab);
}

void dispay_buttons(all_t *s_all)
{
    m_buttons_t *tmp = s_all->s_buttons;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
        if (s_all->s_game.seconds_button < 0.01)
            continue;
        sfFloatRect rect = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1
        && tmp->position.y > 880) {
            tmp->position.y -= 10;
            sfSprite_setPosition(tmp->sprite, tmp->position);
        } else if (tmp->position.y < 940
        && sfFloatRect_contains(&rect, mouse.x, mouse.y) == 0) {
            tmp->position.y += 10;
            sfSprite_setPosition(tmp->sprite, tmp->position);
        }
    }
    if (s_all->s_game.seconds_button > 0.01)
        sfClock_restart(s_all->s_game.clock_button);
}