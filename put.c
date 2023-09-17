#include "main.h"
/**
 * _put - print string
 * @ptr: string
 * Return: ptr - a
*/
int _put(char *ptr)
{
	char *c = ptr;

	while (*ptr)
	{
	_putchar(*ptr++);
	}
	return (ptr - c);
}
/**
 * _putchar - write the character
 * @c: character
 * Return: 1
 *
*/
int _putchar(int c)
{
	int i;
	char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
	write(1, buf, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	{
	buf[i++] = c;
	}
	return (1);
}
