/*
** PROJECT, 2019
** dantestar
** File description:
** generator
*/

#include "dante.h"

#define ROW_SIZE(y) (sizeof(char *) * (y + 1))
#define MAZE_SIZE(y, x) (ROW_SIZE(y) * (sizeof(char) * (x + 1)))

__attribute__((cold))maze_t *alloc_maze(const size_t y, const size_t x, const bool p, const bool v)
{
    void *ptr = malloc(sizeof(maze_t) + MAZE_SIZE(y, x));
    maze_t *ret = (maze_t *)ptr;

    if (ptr == NULL)
        return NULL;
    ptr += sizeof(maze_t);
    ret->x = x;
    ret->y = y;
    ret->is_perfect = p;
    ret->is_verbose = v;
    ret->map = ptr;
    ret->map[y] = NULL;
    ptr += ROW_SIZE(y);
    memset(ptr, 'X', MAZE_SIZE(y, x) - ROW_SIZE(y));
    for (size_t i = 0; i < y; i++) {
        ret->map[i] = (char *)ptr + x * i + i;
        ret->map[i][x] = '\0';
    }
    return (ret);
}

__attribute__((cold))void dig_out(maze_t *maze)
{
    for (int i = maze->x - 1; i >= 0; i--) {
        maze->map[maze->y - 1][i] = '*';
        if (maze->map[maze->y - 2][i] == '*')
            break;
    }
}

__attribute__ ((hot))int p_maze(maze_t *maze)
{
    coord_t *pos = create_list(NULL, 0, 0);
    int dir = -1;

    do {
        (maze->is_verbose)?(display_maze(maze), printf("\n\n")):(0);
        maze->map[pos->y][pos->x] = '*';
        while ((dir = choose_dir(maze, pos, 0)) == 84 && pos->prev != NULL) {
            pos = pos->prev;
            FREE(pos->next);
        }
        if (dir != 84)
            pos = move(maze, pos, dir);
        (maze->is_verbose)?(usleep(50000)):(0);
    } while (pos->prev != NULL);
    kill_pos(pos);
    dig_out(maze);
    return (0);
}
