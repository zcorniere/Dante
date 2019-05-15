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
        my_putstr(mas->map[i]);
        if (i < mas->y - 1)
            my_putchar('\n');
    }
}

int main(int ac, char **av)
{
    int v = 0;
    int p = 1;
    maze_t *maze = NULL;

    srand(time(NULL));
    if (ac < 3 || ac > 5)
        return (84);
    maze = alloc_maze(atoi(av[2]), atoi(av[1]));
    if (maze == NULL)
        return (84);
    (ac >= 4) ?(p = my_strcmp(av[3], "perfect")):(0);
    (ac >= 5) ?(v = atoi(av[4])):(v = 0);
    if (p == 0)
        p_maze(maze, v);
    else
        int_maze(maze, v);
    display_maze(maze);
    freemaz(maze);
    return (0);
}
