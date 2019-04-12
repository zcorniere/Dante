/*
** EPITECH PROJECT, 2019
** dantestart
** File description:
** direction
*/

#include "../include/dante.h"

int opp_dir(int nb)
{
    if (nb == 0)
        return (2);
    if (nb == 3)
        return (1);
    if (nb == 2)
        return (0);
    if (nb == 1)
        return (3);
    return (84);
}

int choose_dir(maze_t *maze, coord_t *pos, int i)
{
    static int last = -1;
    int dir = -1;
    bool ok = FALSE;

    if (i >= 5)
        return (84);
    dir = rand() % 4;
    if (dir == 0 && last != 0 && pos->y > 1)
        if (maze->map[pos->y - 2][pos->x] != '*')
            ok = TRUE;
    if (dir == 1 && last != 1 && pos->x < maze->x - 2)
        if (maze->map[pos->y][pos->x + 2] != '*')
            ok = TRUE;
    if (dir == 2 && last != 2 && pos->y < maze->y - 2)
        if (maze->map[pos->y + 2][pos->x] != '*')
            ok = TRUE;
    if (dir == 3 && last != 3 && pos->x > 1)
        if (maze->map[pos->y][pos->x - 2] != '*')
            ok = TRUE;
    if (ok == FALSE) {
        dir = choose_dir(maze, pos, i + 1);
        last = opp_dir(dir);
    }
    return (dir);
}

int move(maze_t *maze, coord_t *pos, int dir)
{
    switch (dir) {
    case (0):
        maze->map[pos->y - 1][pos->x] = '*';
        pos->next = create_list(pos->y - 2, pos->x);
        break;
    case (1):
        maze->map[pos->y][pos->x + 1] = '*';
        pos->next = create_list(pos->y, pos->x + 2);
        break;
    case (2):
        maze->map[pos->y + 1][pos->x] = '*';
        pos->next = create_list(pos->y + 2, pos->x);
        break;
    case(3):
        maze->map[pos->y][pos->x - 1] = '*';
        pos->next = create_list(pos->y, pos->x - 2);
        break;
    }
    return (0);
}
