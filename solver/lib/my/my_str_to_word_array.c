/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** str to word array
*/

#include "../../include/my.h"

static int calc_row(char const *str, char c)
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

char **my_str_to_word_array(char const *str, char c)
{
    int row = calc_row(str, c);
    int j = 0;
    char **tab = malloc(sizeof(char *) * (row + 1));

    if (str == NULL || tab == NULL)
        return (NULL);
    tab[row] = NULL;
    for (int i = 0; i < row; i++) {
        tab[i] = malloc(sizeof(char) * 256);
        for (int k = 0; k < 255; k++)
            tab[i][k] = '\0';
        for (int k = 0; str[j] != c && str[j] != '\0'; k++)
            tab[i][k] = str[j++];
        j++;
    }
    return (tab);
}
