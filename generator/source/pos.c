/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** pos_malloc
*/

#include "../include/dante.h"

coord_t *create_list(int y, int x)
{
    static coord_t *prev = NULL;
    coord_t *ret = malloc(sizeof(coord_t));

    ret->prev = prev;
    ret->y = y;
    ret->x = x;
    ret->next = NULL;
    prev = ret;
    return (ret);
}
