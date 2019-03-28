/*
** EPITECH PROJECT, 2018
** my_str_isnum.c
** File description:
** is num
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i])
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
            i++;
        else
            return (0);
    return (1);
}
