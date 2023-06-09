#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	va_start(args, format);

	while (*format != '\0')
	{
		/* Print characters when fomrat identifier '%' present */
		if (*format == '%')
		{
			format++;

			/* Handle conversion specifiers */
			switch (*format) {
				case 'c':
				{
					int c = va_arg(args, int);
					fputc(c, stdout);
					count++;
					break;
				}
				case 's':
				{
					char *str = va_arg(args, char *);
					fputs(str, stdout);
					count += strlen(str);
					break;
				}
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;

	}

	va_end(args);
	return count;
}
