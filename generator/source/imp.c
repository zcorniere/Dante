/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** generate unperfect
*/

#include "../include/dante.h"

int int_maze(int x, int y)
{
    int nb;

    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            nb = rand() % 2;
            if (nb == 0)
                printf("%c", '*');
            else if (nb == 1)
                printf("%c", 'X');
        }
        printf("\n");
    }
    return (0);
}
