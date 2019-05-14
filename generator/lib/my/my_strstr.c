/*
** EPITECH PROJECT, 2018
** my_strstr.c
** File description:
** strstr
*/

#include "../../include/my.h"

char *my_strstr(char *str, char const *to_find)
{
    int x = 0;
    int y = 0;
    int d = 0;

    while (str[x] != '\0') {
        y = x;
        d = 0;
        while ((str[y] == to_find[d]) && (to_find[d] != '\0')) {
            if (to_find[d] == '\0')
                return (str);
            y = y + 1;
            d = d + 1;
        }
        x = x + 1;
    }
    return ('\0');
}
