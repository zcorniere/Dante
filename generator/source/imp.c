/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** generate unperfect
*/

#include "../include/dante.h"

int int_maze(maze_t *maze, int v)
{
    int x = 0;
    int y = 0;

    p_maze(maze, v);
    fprintf(stderr, "\nimperfect\n");
    for (int i = 0; i < (maze->y + maze->x); i++) {
        x = rand() % maze->x - 1;
        y = rand() % maze->y - 1;
        x = ABS(x);
        y = ABS(y);
        maze->map[y][x] = '*';
    }
    return (0);
}
