#include "main.h"
/**
 * get_precision - get precision
 * @s: string
 * @param: parameters struct
 * @arg: argument
 * Return: s
 *
*/
char *get_precision(char *s, param_t *param, va_list arg)
{
	int l = 0;

	if (*s != '.')
	{
	return (s);
	}
	s++;
	if (*s == '*')
	{
	l = va_arg(arg, int);
	s++;
	}
	else
	{
	while (is_digit(*s))
	{
	l = l * 10 + (*s++ - '0');
	}
	}
	param->precision = l;
	return (s);
}
