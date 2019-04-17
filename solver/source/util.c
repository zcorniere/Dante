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
    for (int i = 0; tab[i]; i++)
        FREE(tab[i]);
    FREE(tab);
}

int len_to(char const *str, char c)
{
    int len = 0;

    for ( ;str[len] && str[len] != c ;len++);
    return (len);
}

int row_of(char const *str, char c)
{
    int ret = 1;

    if (str == NULL)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c) {
            ret++;
        }
    return (ret);
}

char **str_to_array(char const *str, char c)
{
    int row = row_of(str, c);
    int len = len_to(str, c);
    int j = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (row + 1));
    if (str == NULL || tab == NULL)
        return (NULL);
    tab[row] = NULL;
    for (int i = 0; i < row; i++) {
        tab[i] = malloc(sizeof(char) * (len + 1));
        tab[i][len - 1] = '\0';
        tab[i][len] = '\0';
        for (int k = 0; str[j] != c && str[j] != '\0'; k++)
            tab[i][k] = str[j++];
        j++;
    }
    return (tab);
}
