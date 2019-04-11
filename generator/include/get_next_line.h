/*
** EPITECH PROJECT, 2018
** get next line
** File description:
** header file
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE (16)
#endif /* !READ_SIZE */

#ifndef STR_SIZE
#define STR_SIZE (16)
#endif /* !STR_SIZE */

char *get_next_line(int fd);
