/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_strlen
*/

#include "utils.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);

    for (; str[i] != '\0'; i++);

    return (i);
}
