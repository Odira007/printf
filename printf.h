#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>
#include <stdio.h>

/**
 * struct type - a struct containing a format identifier and a print function
 * @letter: a char that corresponds to a specified printf format identifier
 * @func: a function pointer that accepts a va_list object param & returns void
 */
typedef struct type
{
        char letter;
        void (*func)(va_list);
} type_t;

int _printf(const char *format, ...);
#endif /* PRINTF_H */
