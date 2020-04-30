/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** load
*/

#include "rpg.h"
#include "utils.h"

void check_id(load_t *temp, all_t *s_all)
{
    if (temp->id == 1) {
        load(s_all, "saves/save1");
    }
    if (temp->id == 2) {
        load(s_all, "saves/save2");
    }
    if (temp->id == 3) {
        load(s_all, "saves/save3");
    }
    s_all->s_game.scene = SPAWN;
}

void check_button(load_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect button = sfSprite_getGlobalBounds(temp->button);
    if (sfFloatRect_contains(&button, mouse_pos.x, mouse_pos.y) &&
    temp->fion == 0) {
        sfSprite_setTexture(temp->button, temp->hover, sfTrue);
    }
    else if (temp->fion == 0) {
        sfSprite_setTexture(temp->button, temp->normal, sfTrue);
    }
}

void click_button(load_t *temp, all_t *s_all)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(s_all->s_game.window);
    sfFloatRect button = sfSprite_getGlobalBounds(temp->button);
    if (sfFloatRect_contains(&button, mouse_pos.x, mouse_pos.y)) {
        if (s_all->s_game.event.mouseButton.type == sfEvtMouseButtonPressed) {
            s_all->s_game.event.mouseButton.type = 0;
            temp->fion = 1;
            sfSprite_setTexture(temp->button, temp->click, sfTrue);
        }
        if (s_all->s_game.event.mouseButton.type ==
        sfEvtMouseButtonReleased) {
            temp->fion = 0;
            s_all->s_game.event.mouseButton.type = 0;
            check_id(temp, s_all);
            sfSprite_setTexture(temp->button, temp->normal, sfTrue);
        }
    }
}

void display_load_slots(all_t *s_all)
{
    load_t *temp = s_all->s_load;
    if (s_all->s_game.scene == LOAD && s_all->s_effect.anim > 45) {
        while (temp != NULL) {
            click_button(temp, s_all);
            check_button(temp, s_all);
            sfRenderWindow_drawSprite(s_all->s_game.window, temp->hero, NULL);
            sfRenderWindow_drawText(s_all->s_game.window,
                temp->p_name_tx, NULL);
            sfRenderWindow_drawText(s_all->s_game.window,
                temp->level_tx, NULL);
            sfRenderWindow_drawSprite(s_all->s_game.window,
                temp->button, NULL);
            temp = temp->next;
        }
    }
}