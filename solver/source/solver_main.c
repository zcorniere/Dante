/*
** EPITECH PROJECT, 2018
** Untitled (Workspace)
** File description:
** solver_main.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **brain_init(char **map, coords_t *here, coords_t *max);

int nbr_ln(char **map)
{
    int len = 0;
    while (map[len++]);
    return (len - 1);
}

char **read_map(int fd)
{
    char *tmp;
    struct stat buff;

    fstat(fd, &buff);
    tmp = malloc(sizeof(char) * buff.st_size);
    read(fd, tmp, buff.st_size);
    return (my_str_to_word_array(tmp, '\n'));
}

int main(int ac, char **av)
{
    coords_t *max = malloc(sizeof(coords_t));
    coords_t *here = malloc(sizeof(coords_t));
    int fd;
    char **map;

    if (ac != 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    map = read_map(fd);
    max->x = my_strlen(map[0]);
    max->y = nbr_ln(map);
    here->x = 0;
    here->y = 0;
    map = brain_init(map, here, max);
    return (0);
}