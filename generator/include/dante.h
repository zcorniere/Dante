/*
** EPITECH PROJECT, 2019
** dante star
** File description:
** header
*/

#include "my.h"
#include "macros.h"
#include <string.h>
#include <time.h>
#include <stdio.h>
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

void freemaz(maze_t *maz);
void kill_pos(coord_t *pos);

void display_maze(maze_t *mas);

int int_maze(maze_t *maze, int v);

maze_t *alloc_maze(int y, int x);
int p_maze(maze_t *maze, int v);

int choose_dir(maze_t *maze, coord_t *pos, int i);
coord_t *move(maze_t *maze, coord_t *pos, int dir);

int is_blocked(maze_t *maze, coord_t *pos);
int build_wall(maze_t *maze, coord_t *pos, int dir);

coord_t *create_list(coord_t *pos, int y, int x);

#endif
