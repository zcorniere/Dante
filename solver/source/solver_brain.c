/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** solver_brain.c
*/

#include "../include/my.h"
#include "../include/struct.h"
#include <stdio.h>

int nbr_ln(char **map);

coords_t *set_coords(int x, int y, coords_t *it);

int verif_around(char **map, coords_t *next, coords_t *max)
{
    int n = 0;
    int out = 0;
    int mv_x[5] = {0, 1, 0, -1, 0};
    int mv_y[5] = {0, 0, -1, 0, 1};

    for ( ; n <= 5 ; n++)
        if ((next->x + mv_x[n]) < max->x && (next->x + mv_x[n]) >= 0 &&
        (next->y + mv_y[n]) < max->y && (next->y + mv_y[n]) >= 0)
            out += (map[next->y + mv_y[n]][next->x + mv_x[n]] == '*');
    return (out);
}

coords_t *verif_backward(int n, coords_t *here, char **map, coords_t *next)
{
    int re_x[5] = {0, -1, 0, 1, 0};
    int re_y[5] = {0, 0, 1, 0, -1};

    if (map[here->y + re_y[n]][here->x + re_x[n]] == ('0' + n)) {
        next = set_coords((here->x + re_x[n]), (here->y + re_y[n]), next);
    }
    return (next);
}

coords_t *back_track(char **map, coords_t *here, coords_t *max)
{
    coords_t *next = malloc(sizeof(coords_t));
    int n = 0;
    int re_x[5] = {0, -1, 0, 1, 0};
    int re_y[5] = {0, 0, 1, 0, -1};

    next = set_coords(here->x, here->y, next);
    while (!verif_around(map, here, max)) {
        map[here->y][here->x] = '@';
        if (n == 5)
            exit (1);
        if ((here->x + re_x[n]) < max->x && (here->x + re_x[n]) >= 0 &&
        (here->y + re_y[n]) < max->y && (here->y + re_y[n]) >= 0)
            next = verif_backward(n, here, map, next);
        if (next->x != here->x || next->y != here->y) {
            here = set_coords(next->x, next->y, here);
            n = 0;
        } else
            n++;
    }
    map[here->y][here->x] = '*';
    return (next);
}

coords_t *verif_onward(int n, coords_t *here, char **map, coords_t *next)
{
    int mv_x[5] = {0, 1, 0, -1, 0};
    int mv_y[5] = {0, 0, -1, 0, 1};

    if (map[here->y + mv_y[n]][here->x + mv_x[n]] == '*') {
        next = set_coords((here->x + mv_x[n]), (here->y + mv_y[n]), next);
        map[here->y][here->x] = '0' + n;
    }
    return (next);
}

char **brain_init(char **map, coords_t *here, coords_t *max)
{
    coords_t *next = malloc(sizeof(coords_t));
    int mv_x[5] = {0, 1, 0, -1, 0};
    int mv_y[5] = {0, 0, -1, 0, 1};
    int n = 0;

    while (here->x != (max->x - 1) || here->y != (max->y - 1)) {
        if (n == 5) {
            here = back_track(map, here, max);
            n = 0;
        }
        if ((here->x + mv_x[n]) < max->x && (here->x + mv_x[n]) >= 0 &&
        (here->y + mv_y[n]) < max->y && (here->y + mv_y[n]) >= 0)
            next = verif_onward(n, here, map, next);
        if (next->x != here->x || next->y != here->y) {
            here = set_coords(next->x, next->y, here);
            n = 0;
        } else
            n++;
    }
    map[here->y][here->x] = '5';
    return (map);
}
