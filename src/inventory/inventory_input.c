/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** inventory_input.c
*/

#include <SFML/Graphics.h>

sfBool is_key_released(sfEvent *e, sfKeyCode key)
{
    if (e->key.code == key && e->key.type == sfEvtKeyReleased) {
        e->mouseButton.type = -1;
        return sfTrue;
        }
    return sfFalse;
}

sfBool is_key_presssed(sfEvent *e, sfKeyCode key)
{
    if (e->key.code == key && e->key.type == sfEvtKeyPressed) {
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_button_released(sfEvent *e, sfMouseButton button)
{
    if (e->mouseButton.button == button &&
            e->mouseButton.type == sfEvtMouseButtonReleased) {
        e->mouseButton.type = -1;
        return sfTrue;
    }
    return sfFalse;
}

sfBool is_button_pressed(sfEvent *e, sfMouseButton button)
{
    if (e->mouseButton.button == button &&
            e->mouseButton.type == sfEvtMouseButtonPressed) {
        return sfTrue;
    }
    return sfFalse;
}
