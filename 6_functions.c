#include "main.h"
#include <stdio.h>

/**
 * _print_char - prints character
 * @c: list of arguments, va_list
 * Return: the number of printed chars, int
 */
int _print_char(va_list c)
{
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	return (1);
}

/**
 * _print_str - prints the string, char by char
 * @s: list of arguments, va_list
 * Return: the number of printed chars, int
 */
int _print_str(va_list s)
{
	int i, count = 0;
	char *sbuf = va_arg(s, char *);

	if (sbuf == NULL)
		sbuf = "(null)";

	for (i = 0; sbuf[i]; i++)
	{
		write(1, &sbuf[i], 1);
		count += 1;
	}
	return (count);
}

/**
 * _print_int - prints a decimal integer
 * @i: list of arguments, va_list
 * Return: the number of printed chars, int
 */
int _print_int(va_list i)
{
	int a, expo = 1, len = 0;
	unsigned int n;
	char pr;

	a = va_arg(i, int);

	if (a < 0)
	{
		pr = '-';
		len = len + write(1, &pr, 1);
		n = a * -1;
	}
	else
		n = a;
	while (n / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		pr = n / expo + '0';
		len = len + write(1, &pr, 1);
		n = n % expo;
		expo = expo / 10;
	}
	return (len);
}

/**
 * _print_unsigned - prints an unsigned number
 * @u: list of arguments
 * Return: number of printed chars, int
 */
int _print_unsigned(va_list u)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(u, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
 * _print_rev - prints reverse
 * @r: list of args
 * Return: num of printed chars
 */
int _print_rev(va_list r)
{
	char *st;
	int i, j = 0;

	st = va_arg(r, char *);
	if (st == NULL)
		st = ")llun(";
	for (i = 0; st[i] != '\0'; i++)
		;
	for (i -= 1 ; i >= 0; i--)
	{
		_putchar(st[i]);
		j++;
	}
	return (j);
}
