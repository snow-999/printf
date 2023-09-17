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
int print_integer(va_list arg, param_t *param)
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
/**
 * print_string - print string
 * @arg: argument
 * @param: parameters struct
 * Return: s
 *
*/
int print_string(va_list arg, param_t *param)
{
	char *ptr = va_arg(arg, char *), pd_char = ' ';
	unsigned int p = 0, s = 0, x = 0, z;
	(void)param;

	switch ((int)(!ptr))
	{
	case 1:
		ptr = NULL_STRING;
	}
	z = p = length(ptr);
	if (param->precision < p)
	{
	z = p = param->precision;
	}
	if (param->minus_flag)
	{
		if (param->precision != UINT_MAX)
		{
		for (x = 0; x < p; x++)
		{
		s = s + _putchar(*ptr++);
		}
		}
		else
		{
		s = s + _put(ptr);
		}
	}
	while (z++ < param->width)
	{
	s += _putchar(pd_char);
	}
	if (!param->minus_flag)
	{
		if (param->precision != UINT_MAX)
		{
		for (x = 0; x < p; x++)
		{
		s += _putchar(*ptr++);
		}
		}
		else
		{
		s += _put(ptr);
		}
	}
	return (s);
}
