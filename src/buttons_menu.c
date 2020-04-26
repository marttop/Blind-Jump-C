/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttons_menu
*/

#include "rpg.h"

char **tab_buttons(void)
{
    char **tab = malloc(sizeof(char *) * 2);
    tab[0] = "sprites/buttons/quit1.png";
    tab[1] = "sprites/buttons/quit2.png";
    return (tab);
}

void init_buttons(all_t *s_all)
{
    char **tab = tab_buttons();
    m_buttons_t *old = NULL;
    sfVector2f pos = {100, 940};
    for (int i = 0, id = 0; id != 1; i += 2, pos.x += 200, id++) {
        m_buttons_t *tmp = malloc(sizeof(m_buttons_t));
        tmp->sprite = sfSprite_create();
        tmp->button1 = sfTexture_createFromFile(tab[i], NULL);
        tmp->button2 = sfTexture_createFromFile(tab[i + 1], NULL);
        sfSprite_setTexture(tmp->sprite, tmp->button1, sfTrue);
        sfSprite_setPosition(tmp->sprite, pos);
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
    for (; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(s_all->s_game.window, tmp->sprite, NULL);
    }
}