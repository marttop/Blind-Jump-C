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
    if (read(fd, &c, 1) < 1)
        return -1;
    buf[idx] = c;
    buf[idx + 1] = '\0';
    idx++;
    return idx;
}

int quit_dialog(all_t *s_all)
{
    sfRenderWindow_drawText(s_all->s_game.window,
    s_all->s_chatbox.text, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue){
        s_all->s_chatbox.buff[0] = '\0';
        s_all->s_chatbox.op = 0;
        s_all->s_chatbox.idx = 0;
        s_all->s_chatbox.car = 0;
        return 1;
    }
    else
        return 0;
}

int start_dialog(all_t *s_all, char *filepath)
{
    int i = 0;
    sfRenderWindow_drawRectangleShape(s_all->s_game.window,
    s_all->s_chatbox.box, NULL);
    open_file(s_all, filepath);
    if (s_all->s_chatbox.op == 1 && s_all->s_chatbox.idx != -1)
        i = read_chat_file(s_all);
    else if (s_all->s_chatbox.idx == -1)
        i = wait_close(s_all);
    sfRenderWindow_drawText(s_all->s_game.window, s_all->s_chatbox.text, NULL);
    sfRenderWindow_drawSprite(s_all->s_game.window,
    s_all->s_chatbox.eric, NULL);
    return i;

}