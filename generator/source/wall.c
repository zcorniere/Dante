/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** wall-related function
*/

#include "../include/dante.h"

int is_blocked(maze_t *maze, coord_t *pos)
{
    int ret = 0;

    if (pos->y > 0) {
        if (maze->map[pos->y - 1][pos->x] = 'X')
            ret++;
    } else if (pos->y == 0)
        ret++;
    if (pos->y < maze->y) {
        if (maze->map[pos->y + 1][pos->x] == 'X')
            ret++;
    } else if (pos->y == maze->y)
        ret++;
    if (pos->x > 0) {
        if (maze->map[pos->y][pos->x - 1] == 'X')
            ret++;
    } else if (pos->x == 0)
        ret++;
    if (pos->x < maze->x) {
        if (maze->map [pos->y][pos->x + 1] == 'X')
            ret++;
    } else if (pos->x == maze->x)
        ret++;
    return (ret);
}
