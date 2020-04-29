/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** save
*/

#include "rpg.h"
#include "utils.h"

void write_field(char *field, int fd, char *data)
{
    int i = 0;
    char c;
    for (; field[i] != '\0'; i++)
        read(fd, &c, 1);
    read(fd, &c, 1);
    write(fd, data, my_strlen(data));
    write(fd, "/", 1);
    for (; read(fd, &c, 1);)
        if (c == '\n') break;
}

void save(all_t *s_all)
{
    int fd = open("saves/save1", O_RDWR);
    write_field("name", fd, s_all->s_infos.p_name);
    write_field("r", fd, strnbr(s_all->s_custom.p_color.r));
    write_field("g", fd, strnbr(s_all->s_custom.p_color.g));
    write_field("b", fd, strnbr(s_all->s_custom.p_color.b));
    write_field("level", fd, strnbr(s_all->s_infos.level));
    write_field("xp", fd, strnbr(s_all->s_infos.current_xp));
    write_field("maxxp", fd, strnbr(s_all->s_infos.max_xp));
    write_field("hp", fd, strnbr(s_all->s_infos.current_hp));
    write_field("maxhp", fd, strnbr(s_all->s_infos.max_hp));
    write_field("stage", fd, strnbr(s_all->s_map.stage));
    close(fd);
}