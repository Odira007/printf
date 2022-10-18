#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _print_char(va_list c);
int _print_str(va_list s);
int _print_int(va_list i);
int _print_dec(va_list d);
int _print_rev(va_list r);
int _print_bin(va_list b);
int _print_unsigned(va_list u);
int _print_oct(va_list o);
int _print_hex(va_list x);
int _print_heX(va_list X);
int _print_rot13(va_list R);

/**
 * struct intface - interface for printing
 * @id: the character, which identifies the type of the argument
 * @fn: function to run if id matches
 */
typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;

#endif /* main */
