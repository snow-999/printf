#include "main.h"
/**
 * print_from_to - rage char
 * @s: start
 * @t: stop
 * @e: except
 * Return: x
 *
*/
int print_from_to(char *s, char *t, char *e)
{
	int x = 0;

	while (s <= t)
	{
		if (s != e)
		{
		x = x + _putchar(*s);
		}
		s++;
	}
	return (x);
}
/**
 * print_revese - print revese
 * @param: parameters struct
 * @arg: argument
 * Return: sum
 *
*/
int print_revese(va_list arg, param_t *param)
{
	int l, sum = 0;
	char *ptr = va_arg(arg, char *);
	(void)param;

	if (ptr)
	{
		for (l = 0; *ptr; ptr++)
		{
		l++;
		}
		for (; l > 0; l--, ptr++)
		{
		sum += _putchar(*ptr);
		}
	}
	return (sum);
}
/**
 * print_rot - print rot
 * @arg: argument
 * @param: parametrs struct
 * Return: c
 *
*/
int print_rot(va_list arg, param_t *param)
{
	int i, i2;
	int c = 0;
	char array[] = "NOPQRSTUVWXYZABCDEFGHIJKLM	nopqrstuvwxyzabcdefghijklm";
	char *z = va_arg(arg, char *);
	(void)param;

	i = 0;
	i2 = 0;
	while (array[i])
	{
	if ((array[i] >= 'A' && array[i] <= 'Z')
	|| (array[i] >= 'a' && array[i] <= 'z'))
	{
	i2 = array[i] - 65;
	c = c + _putchar(array[i2]);
	}
	else
	{
	c = c + _putchar(array[i]);
	}
	i++;
	}
	return (c);
}
