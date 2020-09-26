/*
** PROJECT, 2019
** dante star
** File description:
** generate unperfect
*/

#include "dante.h"

__attribute__((cold))int int_maze(maze_t *maze)
{
    unsigned x = 0;
    unsigned y = 0;

    p_maze(maze);
    for (unsigned i = 0; i < (maze->y + maze->x); i++) {
        x = rand() % (maze->x - 1);
        y = rand() % (maze->y - 1);
        maze->map[y][x] = '*';
    }
    return (0);
}
