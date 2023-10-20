/*
** PROJECT, 2019
** dantestar
** File description:
** generator
*/

#include "dante.h"

__attribute__((cold))maze_t *alloc_maze(const size_t y, const size_t x, const bool p, const bool v)
{
    unsigned char* ptr = malloc(sizeof(maze_t) + MAZE_SIZE(y, x));
    memset(ptr, 'X', sizeof(maze_t) + MAZE_SIZE(y, x));
    maze_t* const ret = (maze_t*)ptr;

    if (ptr == NULL)
        return NULL;
    ptr += sizeof(maze_t);
    ret->x = x;
    ret->y = y;
    ret->is_perfect = p;
    ret->is_verbose = v;
    ret->map = (char**)ptr;
    ret->map[y] = NULL;
    ptr += ROW_SIZE(y);
    for (size_t i = 0; i < y; i++) {
        ret->map[i] = (char *)ptr + ((x * i) + i);
        ret->map[i][x] = MAZE_LINE_TERMINATION;
    }
    return ret;
}

__attribute__((cold)) void dig_out(const maze_t* const maze)
{
    for (size_t i = maze->x - 1; i != 0; i--) {
        maze->map[maze->y - 1][i] = '*';
        if (maze->map[maze->y - 2][i] == '*')
            break;
    }
}

__attribute__((hot)) int p_maze(const maze_t* const maze)
{
    coord_t *pos = create_list(NULL, 0, 0);
    int dir = -1;

    do {
        if (UNLIKELY(maze->is_verbose)) {
            printf("\033[%zuA\r\033[1K", maze->y + 1);
            display_maze(maze);
            printf("\n\n");
        }
        maze->map[pos->y][pos->x] = '*';
        while ((dir = choose_dir(maze, pos, 0)) == 84 && pos->prev != NULL) {
            pos = pos->prev;
            FREE(pos->next);
        }
        if (dir != 84)
            pos = move(maze, pos, dir);
        if (UNLIKELY(maze->is_verbose)) {
            usleep(5000);
        }

    } while (pos->prev != NULL);
    kill_pos(pos);
    dig_out(maze);
    return 0;
}
