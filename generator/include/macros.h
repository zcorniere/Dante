/*
** EPITECH PROJECT, 2018
** macros
** File description:
** file contaning many usefull macros
*/

#ifndef MACROS_H_
#define MACROS_H_

#define ABS(value) (((value) < (0)) ? (-value) : (value))

#define FREE(_p) do{ free((_p)); (_p) = NULL; } while (0)

#if (defined(__clang__) || defined(__GNUC__))
    #define FORCEINLINE inline __attribute__((always_inline)) /* Force code to be inline */
    #define FORCENOINLINE __attribute__((noinline))           /* Force code to NOT be inline */
    #define UNLIKELY(x) __builtin_expect(!!(x), 0)
    #define LIKELY(x) __builtin_expect(!!(x), 1)
#else
    #define FORCEINLINE inline
    #define FORCENOINLINE
    #define LIKELY(x) (!!(x))
    #define UNLIKELY(x) (!!(x))
#endif

#endif /*MACROS_H_*/
