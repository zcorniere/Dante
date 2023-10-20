/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** header
*/

#include "macros.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef DANTE_H_
#define DANTE_H_

    #define NB_RETRY 2

    #define MAZE_LINE_TERMINATION '\n'

    #define ROW_SIZE(y) (sizeof(char*) * (y + 1))
    #define MAZE_SIZE(y, x) (ROW_SIZE(y) * (sizeof(char) * (x + 1)))

typedef struct maze_s {
    bool is_perfect;
    bool is_verbose;
    size_t x;
    size_t y;
    char **map;
} maze_t;

typedef struct coord_s {
    struct coord_s *prev;
    size_t x;
    size_t y;
    struct coord_s *next;
} coord_t;

void kill_pos(coord_t *pos);

FORCEINLINE void display_maze(const maze_t* const mas)
{
    write(1, mas->map + mas->y + 1, mas->x * mas->y + mas->y);
}

int int_maze(const maze_t* const maze);

maze_t *alloc_maze(const size_t y, const size_t x, const bool p, const bool v);
int p_maze(const maze_t* const maze);

int choose_dir(const maze_t *const maze, const coord_t *const pos, const int i);
coord_t* move(const maze_t* const maze, coord_t* const pos, const int dir);

coord_t* create_list(coord_t* const pos, const int y, const int x);

#endif
