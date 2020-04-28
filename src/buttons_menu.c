/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** buttons_menu
*/

#include "rpg.h"

char **tab_buttons(void)
{
    char **tab = malloc(sizeof(char *) * 6);
    tab[0] = "sprites/buttons/quit1.png";
    tab[1] = "sprites/buttons/quit2.png";
    tab[2] = "sprites/buttons/opts1.png";
    tab[3] = "sprites/buttons/opts2.png";
    tab[4] = "sprites/buttons/save1.png";
    tab[5] = "sprites/buttons/save2.png";
    return (tab);
}

void init_buttons(all_t *s_all)
{
    char **tab = tab_buttons();
    m_buttons_t *old = NULL;
    sfVector2f pos = {100, 940};
    for (int i = 0, id = 0; id != 3; i += 2, pos.x += 140, id++) {
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

void buttons_event(all_t *s_all, m_buttons_t *tmp)
{
    if (tmp->id == 5)
        s_all->s_game.scene = MENU;
    if (tmp->id == 0)
        sfRenderWindow_close(s_all->s_game.window);
    if (tmp->id == 1)
        s_all->s_game.scene = OPT;
}

void click_buttons(all_t *s_all, m_buttons_t *tmp, sfVector2i mouse)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(tmp->sprite);
    if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1
    && s_all->s_game.event.mouseButton.type == sfEvtMouseButtonPressed) {
        s_all->s_game.event.mouseButton.type = 0;
        sfSprite_setTexture(tmp->sprite, tmp->button2, sfTrue);
    }
    if (s_all->s_game.event.mouseButton.type == sfEvtMouseButtonReleased) {
        s_all->s_game.event.mouseButton.type = 0;
        m_buttons_t *temp = tmp;
        for (; temp != NULL; temp = temp->next) {
            rect = sfSprite_getGlobalBounds(temp->sprite);
            if (sfFloatRect_contains(&rect, mouse.x, mouse.y) == 1)
                buttons_event(s_all, temp);
            sfSprite_setTexture(temp->sprite, temp->button1, sfTrue);
        }
    }
}

void dispay_buttons(all_t *s_all, m_buttons_t *buttons)
{
    m_buttons_t *tmp = buttons;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(s_all->s_game.window);
    for (; tmp != NULL; tmp = tmp->next) {
        click_buttons(s_all, tmp, mouse);
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
            sfSprite_setTexture(tmp->sprite, tmp->button1, sfTrue);
        }
    } if (s_all->s_game.seconds_button > 0.01)
        sfClock_restart(s_all->s_game.clock_button);
}