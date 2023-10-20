/*
** PROJECT, 2019
** dantestar
** File description:
** main generator
*/

#include "dante.h"

__attribute__((cold)) void print_help(void)
{
    write(1, "A maze generator\nUSAGE:\n\t./generator x y [perfect] [1]\n", 55);
}

__attribute__((cold))maze_t *check_args(const int ac, const char **av)
{
    bool v = false;
    bool p = false;
    size_t x = 0;
    size_t y = 0;

    if (ac < 3 || ac > 5) {
        return NULL;
    }
    x = atoi(av[1]);
    y = atoi(av[2]);
    if (x < 2 || y < 2)
        return NULL;
    if (ac >= 4)
        p = (strcmp(av[3], "perfect") == 0);
    if (ac >= 5)
        v = (atoi(av[4]) == 1);
    return alloc_maze(y, x, p, v);
}

int main(const int ac, const char **av)
{
    maze_t* const maze = check_args(ac, av);

    srand(time(NULL));

    if (maze == NULL)
        return print_help(), 84;
    if (maze->is_perfect)
        p_maze(maze);
    else
        int_maze(maze);
    display_maze(maze);
    free(maze);
    return 0;
}
