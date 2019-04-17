/*
** EPITECH PROJECT, 2018
** CPE_dante_2018
** File description:
** struct.h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct coords_s
{
    int x;
    int y;
}coords_t;

char **brain_init(char **map, coords_t *here, coords_t *max);

void freedom(char **tab);
char **str_to_array(char const *str, char c);

#endif /*STRUCT_H_*/