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
    int v = 0;
    int p = 0;
    maze_t *maze = NULL;

    srand(time(NULL));
    if (ac < 2 || ac > 5)
        return (84);
    maze = alloc_maze(atoi(av[2]), atoi(av[1]));
    if (maze == NULL)
        return (84);
    (av[3] != NULL) ?(p = atoi(av[3])):(p = 0);
    (av[4] != NULL) ?(v = atoi(av[3])):(v = 0);
    if (p == 0)
        int_maze(maze);
    else if (p == 1)
        p_maze(maze, v);
    display_maze(maze);
    freemaz(maze);
    return (0);
}
