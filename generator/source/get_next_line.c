/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get next line
*/

#include "../include/get_next_line.h"
#include "../include/macros.h"

static char *raw_quit(char **offset, char *str)
{
    FREE(*offset);
    FREE(str);
    return (NULL);
}

static char *is_good(int fd, char *str, char *offset)
{
    if (offset == NULL) {
        offset = malloc(sizeof(char) * (READ_SIZE + 1));
        for (int i = 0; i < READ_SIZE; i++)
            offset[i] = '\0';
    }
    if (fd == -1 || str == NULL || offset == NULL) {
        return (raw_quit(&offset, str));
    }
    for (int i = 0; i < STR_SIZE ; i++)
        str[i] = '\0';
    return (offset);
}

static char *offset_filler(char *offset, int i)
{
    int j = 0;

    i++;
    for (; offset[i] != '\0'; i++)
        offset[j++] = offset[i];
    for (; offset[j] != '\0'; j++)
        offset[j] = '\0';
    return (offset);
}

static char *new_read(char **offset, int *size, int *i, int fd)
{
    *size = read(fd, *offset, READ_SIZE);
    *i = 0;
    return (*offset);
}

char *get_next_line(int fd)
{
    static char *offset = NULL;
    static int first = 1;
    char *str = malloc(sizeof(char) * (STR_SIZE + 1));
    int i = 0;
    int j = 0;
    int size = 1;

    if ((offset = is_good(fd, str, offset)) == NULL)
        return (NULL);
    (first-- == 1) ? (size = read(fd, offset, READ_SIZE)) : (0);
    while (offset[i] != '\n') {
        if (size == 0)
            return (raw_quit(&offset, str));
        while (offset[i] != '\0' && offset[i] != '\n')
            str[j++] = offset[i++];
        if (offset[i] == '\0')
            offset = new_read(&offset, &size, &i, fd);
    }
    offset = offset_filler(offset, i);
    return (str);
}
