/*
** EPITECH PROJECT, 2019
** dantestar
** File description:
** generator
*/

#include "../include/dante.h"

maze_t *alloc_maze(int y, int x)
{
    maze_t *ret = malloc(sizeof(maze_t));

    ret->x = x;
    ret->y = y;
    ret->map = malloc(sizeof(char *) * (y + 1));
    ret->map[y] = NULL;
    for (int i = 0; i < y; i++) {
        ret->map[i] = malloc(sizeof(char) * (x + 1));
        ret->map[i][x] = '\0';
        for (int j = 0; j < x; j++)
            ret->map[i][j] = 'X';
    }
    return (ret);
}

int p_maze(maze_t *maze)
{
    coord_t *pos = create_list(0, 0);
    int dir = -1;

    do {
        maze->map[pos->y][pos->x] = '*';
        while ((dir = choose_dir(maze, pos, 0)) == 84 && pos->prev != NULL)
            pos = pos->prev;
        if (dir != 84) {
            move(maze, pos, dir);
            pos = pos->next;
        }
    } while (pos->prev != NULL);
    maze->map[maze->y - 1][maze->x - 1] = '*';
    if (maze->x % 2 == 0)
        maze->map[maze->y - 1][maze->x - 2] = '*';
    kill_pos(pos);
    return (0);
}
