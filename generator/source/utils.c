/*
** PROJECT, 2019
** dante start
** File description:
** utils
*/

#include "dante.h"

__attribute__((cold))void freemaz(maze_t *maz)
{
    for (int i = 0; i < maz->y; i++)
        free(maz->map[i]);
    free(maz->map);
    free(maz);
}

__attribute__((cold))void kill_pos(coord_t *pos)
{
    while (pos->next != NULL) {
        pos = pos->next;
        free(pos->prev);
    }
    free(pos);
}
