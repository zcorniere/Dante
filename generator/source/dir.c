/*
** PROJECT, 2019
** dantestart
** File description:
** direction
*/

#include "dante.h"

__attribute__((hot, const))inline static int opp_dir(const int nb)
{
    switch (nb) {
        case 0: return 2;
        case 3: return 1;
        case 2: return 0;
        case 1: return 3;
    }
    return 84;
}

__attribute__((hot))int choose_dir(const maze_t *const maze, const coord_t *const pos, const int i)
{
    static int last = -1;
    int dir = -1;
    bool ok = false;

    if (i >= NB_RETRY)
        return 84;
    dir = rand() % 4;
    if (dir == 0 && last != 0 && pos->y > 1)
        ok = maze->map[pos->y - 2][pos->x] != '*';
    else if (dir == 1 && last != 1 && pos->x < maze->x - 2)
        ok = maze->map[pos->y][pos->x + 2] != '*';
    else if (dir == 2 && last != 2 && pos->y < maze->y - 2)
        ok = maze->map[pos->y + 2][pos->x] != '*';
    else if (dir == 3 && last != 3 && pos->x > 1)
        ok = maze->map[pos->y][pos->x - 2] != '*';
    if (!ok)
        dir = choose_dir(maze, pos, i + 1);
    last = opp_dir(dir);
    return dir;
}

__attribute__((hot))coord_t *move(const maze_t *maze, coord_t *pos, const int dir)
{
    switch (dir) {
    case 0:
        maze->map[pos->y - 1][pos->x] = '*';
        pos->next = create_list(pos, pos->y - 2, pos->x);
        break;
    case 1:
        maze->map[pos->y][pos->x + 1] = '*';
        pos->next = create_list(pos, pos->y, pos->x + 2);
        break;
    case 2:
        maze->map[pos->y + 1][pos->x] = '*';
        pos->next = create_list(pos, pos->y + 2, pos->x);
        break;
    case 3:
        maze->map[pos->y][pos->x - 1] = '*';
        pos->next = create_list(pos, pos->y, pos->x - 2);
        break;
    }
    pos = pos->next;
    return pos;
}
