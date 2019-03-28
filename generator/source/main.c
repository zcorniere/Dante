/*
** EPITECH PROJECT, 2019
** dantestar
** File description:
** main generator
*/

#include "../include/dante.h"

void display_maze(maze_t *mas)
{
    for (int i = 0; i < mas->y; i++) {
        for (int j = 0; j < mas->x; j++)
            printf("%c", mas->map[i][j]);
        printf("\n");
    }
}

int main (int ac, char **av)
{
    int x;
    int y;
    int p = 0;
    maze_t *maze = NULL;

    srand(time(NULL));
    if (ac < 2 || ac > 4)
        return (84);
    x = atoi(av[1]);
    y = atoi(av[2]);
    maze = alloc_maze(y, x);
    (av[3] != NULL)?(p = atoi(av[3])):(p = 0);
    if (p == 0)
        int_maze(x, y);
    else if (p == 1)
        p_maze(maze);
    freemaz(maze);
    return (0);
}
