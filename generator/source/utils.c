/*
** PROJECT, 2019
** dante start
** File description:
** utils
*/

#include "../include/dante.h"

__attribute__((cold))void freemaz(maze_t *maz)
{
    for (int i = 0; i < maz->y; i++)
        FREE(maz->map[i]);
    FREE(maz->map);
    FREE(maz);
}

__attribute__((cold))void kill_pos(coord_t *pos)
{
    while (pos->next != NULL) {
        pos = pos->next;
        FREE(pos->prev);
    }
    FREE(pos);
}
