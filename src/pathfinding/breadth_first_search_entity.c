/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** breadth_first_search_entity
*/

#include "rpg.h"

char **process_result(char **maze, queue_t *s_dequeue, queue_t *s_queue)
{
    queue_node_t *tmp = s_dequeue->last;

    maze[s_queue->last->y][s_queue->last->x] = ' ';

    for (; tmp != NULL; tmp = tmp->parent)
        maze[tmp->y][tmp->x] = ' ';

    format_map(maze);

    s_queue = clear_queue(s_queue);
    s_dequeue = clear_queue(s_dequeue);

    return (maze);
}

char **breadth_first_search_entity(char **map, all_t *s_all, int x, int y)
{
    queue_t *s_queue = new_queue();
    queue_t *s_dequeue = new_queue();
    char **maze = copy_map(map);
    sfVector2i pos_start = (sfVector2i){x, y};
    sfVector2i pos_end = find_pos(s_all, 'T');

    s_queue = push_back_queue(s_queue, NULL, pos_start.x, pos_start.y);
    maze[pos_start.y][pos_start.x] = 'W';
    while (s_queue != NULL && check_if_found(s_queue, pos_end) == 0) {
        s_queue = push_new_generation(maze, s_queue, &s_dequeue);
    }

    if (s_queue == NULL) {
        s_dequeue = clear_queue(s_dequeue);
        return (NULL);
    }

    maze = process_result(maze, s_dequeue, s_queue);

    return (maze);
}