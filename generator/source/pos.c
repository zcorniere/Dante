/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** pos_malloc
*/

#include "../include/dante.h"

__attribute__ ((hot))coord_t *create_list(coord_t *prev, int y, int x)
{
    coord_t *ret = malloc(sizeof(coord_t));

    ret->prev = prev;
    ret->y = y;
    ret->x = x;
    ret->next = NULL;
    prev = ret;
    return (ret);
}
