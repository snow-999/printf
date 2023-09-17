#include "main.h"
/**
 * print_char - print char
 * @arg: argument
 * @param: parameters struct
 * Return: sum
*/
int print_char(va_list arg, param_t *param)
{
	char pd_char = ' ';
	unsigned int p = 1, sum = 0, ch = va_arg(arg, int);

	if (param->minus_flag)
	{
	sum = sum + _putchar(ch);
	}
	while (p++ < param->width)
	{
	sum = sum + _putchar(pd_char);
	}
	if (!param->minus_flag)
	{
	sum = sum + _putchar(ch);
	}
	return (sum);
}
/**
 * print_integer - print int
 * @arg: argument
 * @param: parameters struct
 * Return: number
*/
int print_integer(va_list arg, parama_t *param)
{
	long i;

	if (param->l_modifier)
	{
	i = va_arg(arg, long);
	}
	else if (param->h_modifier)
	{
	i = (short int) va_arg(arg, long);
	}
	else
	{
	i = (int)va_arg(arg, int);
	}
	return (print_num(convert(i, 10, 0, param), param));
}
/**
 * print_percent - print percent
 * @arg: argument
 * @param: parameters struct
 * Return: %
*/
int print_percent(va_list arg, param_t *param)
{
	(void)arg;
	(void)param;
	return (_putchar('%'));
}
