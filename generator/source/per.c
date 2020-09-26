/*
** PROJECT, 2019
** dantestar
** File description:
** generator
*/

#include "dante.h"
#define MAZE_SIZE(y, x) ((sizeof(char *) * (y + 1)) * (sizeof(char) * (x + 1)))

__attribute__((cold))maze_t *alloc_maze(const size_t y, const size_t x)
{
    void *ptr = malloc(sizeof(maze_t) + MAZE_SIZE(y, x));
    maze_t *ret = (maze_t *)ptr;

    ptr += sizeof(maze_t);
    ret->x = x;
    ret->y = y;
    ret->map = ptr;
    ret->map[y] = NULL;
    ptr += (sizeof(char *) * (y + 1));
    for (size_t i = 0; i < y; i++) {
        ret->map[i] = (char *)ptr + x * i + i;
        memset(ret->map[i], 'X', x);
        ret->map[i][x] = '\0';
    }
    return (ret);
}

__attribute__ ((hot))int p_maze(maze_t *maze, const int v)
{
    coord_t *pos = create_list(NULL, 0, 0);
    int dir = -1;

    do {
        (v == 1)?(display_maze(maze), printf("\n\n")):(0);
        maze->map[pos->y][pos->x] = '*';
        while ((dir = choose_dir(maze, pos, 0)) == 84 && pos->prev != NULL) {
            pos = pos->prev;
            FREE(pos->next);
        }
        if (dir != 84)
            pos = move(maze, pos, dir);
        (v == 1)?(usleep(50000)):(0);
    } while (pos->prev != NULL);
    maze->map[maze->y - 1][maze->x - 1] = '*';
    if (maze->x % 2 == 0)
        maze->map[maze->y - 1][maze->x - 2] = '*';
    kill_pos(pos);
    return (0);
}
