/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** init_load
*/

#include "rpg.h"
#include "utils.h"

load_t *fill_load_slot(all_t *s_all, load_t *old, sfVector2f pos, int id)
{
    load_t *new = malloc(sizeof(load_t));
    int fd = 0;
    char *level = malloc(20);
    level[0] = '\0';
    my_strcat(level, "Level ");
    new->hero = sfSprite_create();
    new->level_tx = sfText_create();
    new->p_name_tx = sfText_create();
    new->hero_tx = s_all->s_player.hero_tx;
    sfSprite_setTexture(new->hero, new->hero_tx, sfTrue);
    sfSprite_setTextureRect(new->hero, (sfIntRect){406, 109, 20, 31});
    sfSprite_setScale(new->hero, (sfVector2f){4, 4});
    sfText_setFont(new->level_tx, s_all->s_game.font);
    sfText_setFont(new->p_name_tx, s_all->s_game.font);
    if (id == 1)
        fd = open("saves/save1", O_RDWR);
    if (id == 2)
        fd = open("saves/save2", O_RDWR);
    if (id == 3)
        fd = open("saves/save3", O_RDWR);
    new->id = id;
    sfText_setString(new->p_name_tx, read_field("name", fd));
    sfSprite_setColor(new->hero, (sfColor){my_atoi(read_field("r", fd)),
    my_atoi(read_field("g", fd)), my_atoi(read_field("b", fd)), 255});
    my_strcat(level, read_field("level", fd));
    sfText_setString(new->level_tx, level);
    sfText_setPosition(new->p_name_tx, pos);
    sfSprite_setPosition(new->hero, (sfVector2f){pos.x, pos.y + 150});
    sfText_setPosition(new->level_tx, (sfVector2f){pos.x, pos.y + 350});
    new->next = old;
    return (new);
}

void init_load_slots(all_t *s_all)
{
    int i = 1;
    sfVector2f pos = (sfVector2f){450, 200};
    s_all->s_load = NULL;
    for (; i != 4; i++) {
        s_all->s_load = fill_load_slot(s_all, s_all->s_load, pos, i);
        pos.x += 450;
    }
}

void display_load_slots(all_t *s_all)
{
    load_t *temp = s_all->s_load;
    if (s_all->s_game.scene == LOAD && s_all->s_effect.anim > 45) {
        while (temp != NULL) {
            sfRenderWindow_drawSprite(s_all->s_game.window, temp->hero, NULL);
            sfRenderWindow_drawText(s_all->s_game.window,
                temp->p_name_tx, NULL);
            sfRenderWindow_drawText(s_all->s_game.window,
                temp->level_tx, NULL);
            temp = temp->next;
        }
    }
}