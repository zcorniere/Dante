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

coords_t *set_coords(int x, int y, coords_t *it)
{
    it->x = x;
    it->y = y;
    return (it);
}

char **clean_up(char **map, coords_t *max)
{
    int z = 0;

    while (map[z / max->x][z % max->x]) {
        if (map[z / max->x][z % max->x] == '@')
            map[z / max->x][z % max->x] = '*';
        if (map[z / max->x][z % max->x] >= '0' &&
        map[z / max->x][z % max->x] <= '5')
            map[z / max->x][z % max->x] = 'o';
        z++;
        if (!map[z / max->x])
            return (map);
    }
    return (map);
}

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
    tmp = malloc(sizeof(char) * buff.st_size - 1);
    read(fd, tmp, buff.st_size - 1);
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
    max = set_coords(my_strlen(map[0]), nbr_ln(map), max);
    here = set_coords(0, 0, here);
    map = brain_init(map, here, max);
    map = clean_up(map, max);
    my_put_str_array(map);
    return (0);
}
