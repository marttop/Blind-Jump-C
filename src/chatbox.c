/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** chatbox
*/

#include "rpg.h"

void chatbox(all_t *s_all, char *filepath)
{
    if (s_all->s_game.chat == 1) {
        if (start_dialog(s_all, filepath) == 1) {
            s_all->s_game.chat = 0;
            s_all->s_npc.talk = 0;
            return;
        }
    }
}

void init_chatbox(all_t *s_all)
{
    s_all->s_chatbox.clock = sfClock_create();
    s_all->s_chatbox.box = sfRectangleShape_create();
    sfRectangleShape_setSize(s_all->s_chatbox.box, (sfVector2f){1800, 220});
    sfRectangleShape_setFillColor(s_all->s_chatbox.box, sfBlack);
    sfRectangleShape_setOutlineColor(s_all->s_chatbox.box, sfWhite);
    sfRectangleShape_setOutlineThickness(s_all->s_chatbox.box, 1.5);
    sfRectangleShape_setPosition(s_all->s_chatbox.box, (sfVector2f){60, 780});
    s_all->s_chatbox.font = sfFont_createFromFile("font/Cornerstone.ttf");
    s_all->s_chatbox.text = sfText_create();
    sfText_setColor(s_all->s_chatbox.text, sfWhite);
    sfText_setFont(s_all->s_chatbox.text, s_all->s_chatbox.font);
    sfText_setString(s_all->s_chatbox.text, "");
    sfText_setCharacterSize(s_all->s_chatbox.text, 20);
    sfText_setPosition(s_all->s_chatbox.text, (sfVector2f){80, 800});
    s_all->s_chatbox.sec = 0, s_all->s_game.chat = 0;
    init_chatbox2(s_all);
}

int add_letter(int fd, int idx, char *buf)
{
    char c;
    if(read(fd, &c, 1) < 1) {
        return -1;
    }
    buf[idx] = c;
    buf[idx + 1] = '\0';
    idx++;
    return idx;
}

int quit_dialog(all_t *s_all, int idx)
{
    while (idx == -1) {
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_chatbox.text, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue)
            return 1;
    }
    return 0;
}

int start_dialog(all_t *s_all, char *filepath)
{
    char *buf = malloc(sizeof(char) * 2000);
    buf[0] = '\0';
    int fd = open(filepath, O_RDONLY), idx = 0, i = 0;
    float sec = 0.05;
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    s_all->s_chatbox.box, NULL);
    while (idx != -1) {
        dialog_time(s_all);
        if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue) sec = 0.0;
        else sec = 0.05;
        if (i == 130) buf[idx] = '\n', idx++, i = 0;
        if (s_all->s_chatbox.sec > sec)
            idx = add_letter(fd, idx, buf), i++, add_text(s_all, buf);
        sfRenderWindow_drawText(s_all->s_game.window,
        s_all->s_chatbox.text, NULL), sfRenderWindow_drawSprite(s_all->s_game.
        window, s_all->s_chatbox.eric, NULL);
        sfRenderWindow_display(s_all->s_game.window);
    } close(fd), free(buf);
    return quit_dialog(s_all, idx);
}