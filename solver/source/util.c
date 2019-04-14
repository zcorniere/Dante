/*
** EPITECH PROJECT, 2019
** solver
** File description:
** freedom
*/

#include "../include/macros.h"
#include <stddef.h>

void freedom(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        FREE(tab[i]);
    FREE(tab);
}
