/*
** PROJECT, 2019
** dante star
** File description:
** pos_malloc
*/

#include "dante.h"

__attribute__((hot)) FORCEINLINE coord_t* create_list(coord_t* const prev, const int y, const int x)
{
    coord_t *ret = malloc(sizeof(coord_t));

    if (prev) {
        prev->next = ret;
    }
    ret->prev = prev;
    ret->y = y;
    ret->x = x;
    return ret;
}
