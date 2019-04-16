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
        if (i < mas->y - 1)
            printf("\n");
    }
}

int main (int ac, char **av)
{
    int v = 0;
    int p = 0;
    maze_t *maze = NULL;

    srand(time(NULL));
    if (ac < 3 || ac > 5)
        return (84);
    maze = alloc_maze(atoi(av[2]), atoi(av[1]));
    if (maze == NULL)
        return (84);
    (ac >= 4) ?(p = atoi(av[3])):(p = 0);
    (ac >= 5) ?(v = atoi(av[3])):(v = 0);
    if (p == 0)
        int_maze(maze);
    else if (p == 1)
        p_maze(maze, v);
    display_maze(maze);
    freemaz(maze);
    return (0);
}
