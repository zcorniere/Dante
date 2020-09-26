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

typedef struct maze_s {
    int x;
    int y;
    char **map;
} maze_t;

typedef struct coord_s {
    struct coord_s *prev;
    int x;
    int y;
    struct coord_s *next;
} coord_t;

void kill_pos(coord_t *pos);

void display_maze(const maze_t *const mas);

int int_maze(maze_t *maze, int v);

maze_t *alloc_maze(const size_t y, const size_t x);
int p_maze(maze_t *maze, const int v);

int choose_dir(const maze_t *maze, const coord_t *pos, const int i);
coord_t *move(maze_t *maze, coord_t *pos, const int dir);

coord_t *create_list(coord_t *pos, const int y, const int x);

#endif
