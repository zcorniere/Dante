/*
** EPITECH PROJECT, 2018
** macros
** File description:
** file contaning many usefull macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#define ABS(value) (((value) < (0)) ? (-value) : (value))

#define FREE(_p) do{                            \
        free((_p));                           \
        (_p) = NULL;                            \
    } while(0)

#define TRUE 1
#define FALSE 0

typedef int bool;
#endif /*MACROS_H_*/
