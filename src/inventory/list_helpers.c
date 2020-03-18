/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2019
** File description:
** list_helpers.c
*/

#include <rpg.h>
#include <stdlib.h>

void dealloc(struct node *n, void *data)
{
    free(data);
    free(n);
}

t_node *add_node(t_node *node, void *data)
{
    t_node *new = malloc(sizeof(t_node));
    static int i = 0;
    new->dealloc = &dealloc;
    new->id = i++;
    new->data = data;
    new->next = node;
    return new;
}

void iterate_slots(t_node *inv, all_t *d)
{
    t_node *tmp = inv;
    t_slot *slot = ((t_slot *)tmp->data);
    while (tmp->next)
    {
        slot = ((t_slot *)tmp->data);
        slot->on_hover(d, slot, d->s_game.window);
        tmp = tmp->next;
    }
}

void get_empty_slot(t_node *inv, t_weapon *w)
{
    t_node *tmp = inv;
    t_slot *slot;
    while (tmp->next) {
        slot = ((t_slot *)tmp->data);
        if (!slot->has_item) {
            slot->weapon = w;
            slot->has_item = 1;
            break;
        }
        tmp = tmp->next;
    }
}

void iterate_dealloc(t_node *n)
{
    t_node *tmp = n;
    t_node *tmp2;
    while (tmp->next) {
        tmp2 = tmp;
        tmp = tmp->next;
        tmp->dealloc(tmp2, tmp2->data);
    }
}