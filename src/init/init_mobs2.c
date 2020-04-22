/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_mobs2
*/

#include "rpg.h"
#include "utils.h"

void init_mob_interface(mob_t *new, char type, all_t *s_all)
{
    int lvl = rand() % (s_all->s_map.stage + 1) + s_all->s_map.stage;
    new->text = sfText_create();
    sfText_setFont(new->text, s_all->s_game.font);
    sfText_setPosition(new->text, (sfVector2f)
        {new->mob_pos.x - 10, new->mob_pos.y - 10});
    new->name = malloc(25), new->name[0] = '\0'; new->lvl = lvl;
    if (type == 'B') {
        my_strcat(new->name, "Blob lvl ");
        new->hp = (150 * lvl) / 2;
    } if (type == 'A') {
        my_strcat(new->name, "Roball lvl ");
        new->hp = (100 * lvl) / 2;
    } my_strcat(new->name, strnbr(lvl)), sfText_setCharacterSize(new->text, 7);
    sfText_setString(new->text, new->name);
    sfText_setColor(new->text, (sfColor){255, 255, 255, 255});
}

void display_mobs2(mob_t *temp, all_t *s_all)
{
    sfRenderWindow_drawSprite(s_all->s_game.window, temp->shadow, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window, temp->mob, NULL);
    sfRenderWindow_drawText(s_all->s_game.window, temp->text, NULL);
    sfText_setPosition(temp->text, (sfVector2f)
        {temp->mob_pos.x - 20, temp->mob_pos.y - 15});
    sfSprite_setPosition(temp->mob, temp->mob_pos);
    sfSprite_setPosition(temp->shadow, temp->shadow_pos);
}