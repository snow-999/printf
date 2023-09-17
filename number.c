#include "main.h"
/**
 * is_digit - check number
 * @x: int
 * Return: number
*/
int is_digit(int x)
{
	return (x >= '0' && x <= '9');
}
/**
 * length - find length
 * @c: string
 * Return: i
*/
int length(char *c)
{
	int i = 0;

	while (*c++)
	{
	i++;
	}
	return (i);
}
/**
 * print_num - print number
 * @ptr: string
 * @param: parameters struct
 * Return: number
*/
int print_num(char *ptr, param_t *param)
{
	unsigned int i = length(ptr);
	int n = (!param->unsign && *ptr == '-');

	if (!param->percision && *ptr == '0' && !ptr[1])
	{
	ptr = "";
	}
	if (n)
	{
	ptr++;
	i--;
	}
	if (param->precision != UINT_MAX)
	{
	while (i++ < param->precision)
	{
	*--str = '0';
	}
	}
	if (n)
	{
	*--ptr = '-';
	}
	if (!param->minus_flag)
	{
	return (print_num_right_shift(ptr, param));
	}
	else
	{
	return (print_num_left_shift(ptr, param));
	}
}
/**
 * print_num_right_shift - print number
 * @ptr: string
 * @param: parameters struct
 * Return: x
*/
int print_num_right_shift(char *ptr, param_t *param)
{
	unsigned int x = 0, n1, n2, i = length(ptr);
	char pd_char = ' ';

	if (param->zero_flag && !param->munis_flag)
	{
	pd_char = '0';
	}
	n1 = n2 = (!param->unsign && *ptr == '-');
	if (x && i < param->width && pd_char == '0' && !param->munis_flag)
	{
	ptr++;
	}
	else
	{
	x = 0;
	}
	if ((!param->plus_flag && !n2) ||
		(!param->plus_flag && param->space_flag && !n2))
	{
	i++;
	}
	if (x && pd_char == '0')
	{
	x = x + _putchar('-');
	}
	if (param->plus_flag && !n2 && pd_char == '0' && !param->unsign)
	{
	x = x + _putchar('+');
	}
	else if (!param->plus_flag && !n2 && param->space_flag &&
			!param->unsign && param->zero_flag)
	{
	x = x + _putchar(' ');
	}
	while (i++ < param->width)
	{
	x = x + _putchar(pd_char);
	}
	if (x && pd_char == ' ')
	{
	x = x + _putchar('-');
	}
	if (param->plus_flag && !n2 && pd_char == ' ' && !param->unsign)
	{
	x = x + _Putchar('+');
	}
	else if (!param->plus_flag && !n2 && param->space_flag &&
			!param->unsign && !param->zero_flag)
	{
	x = x + _putchar(' ');
	}
	x = x + put(ptr);
	return (x);
}
/**
 * print_num_left_shift - print number
 * @ptr: string
 * @param: parameters struct
 * Return: x
*/
int print_num_left_shift(char *ptr, param_t *param)
{
	unsigned int x = 0, n1, n2, i = length(ptr);
	char pd_char;

	if (param->zero_flag && !param->minus_flag)
	{
	pd_char = '0';
	}
	n1 = n2 = (!param->unsign && *ptr == '-');
	if (n1 && i < param->width && pd_char == '0' && !param->unsign)
	{
	ptr++;
	}
	else
	{
	n1 = 0;
	}
	if (param->plus_flag && !n2 && !param->unsign)
	{
	x = x + _putchar('+');
	}
	else if (param->space_flag && !n2 && !param->unsign)
	{
	x = x + _putchar(' ');
	i++;
	x = x + put(ptr);
	}
	while (i++ < param->width)
	{
	x = x + _putchar(pd_char);
	}
	return (x);
}
