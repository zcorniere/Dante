/*
** PROJECT, 2019
** dante star
** File description:
** generate unperfect
*/

#include "dante.h"

__attribute__((cold))int int_maze(maze_t *maze, int v)
{
    int x = 0;
    int y = 0;

    p_maze(maze, v);
    for (int i = 0; i < (maze->y + maze->x); i++) {
        x = rand() % maze->x - 1;
        y = rand() % maze->y - 1;
        x = ABS(x);
        y = ABS(y);
        maze->map[y][x] = '*';
    }
    return (0);
}
