#include "main.h"
/**
 * print_hex - print hex
 * @param: parameter struct
 * @arg: argument
 * Return: number
 *
*/
int print_hex(va_list arg, param_t *param)
{
	unsigned long x;
	int c = 0;
	char *ptr;

	if (param->l_modifier)
	{
	x = (unsigned long)va_arg(arg, unsigned long);
	}
	else if (param->h_modifier)
	{
	x = (unsigned short int)va_arg(arg, unsigned int);
	}
	else
	{
	x = (unsigned int)va_arg(arg, unsigned int);
	}
	ptr = convert(x, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, param);
	if (param->hashtag_flag && x)
	{
	*--ptr = 'x';
	*--ptr = '0';
	}
	param->unsign = 1;
	return (c += print_num(ptr, param));
}
/**
 * print_HEX - print HEX
 * @arg: argument
 * @param: parametrs struct
 * Return: number
 *
*/
int print_HEX(va_list arg, param_t *param)
{
	unsigned long x;
	int c = 0;
	char *ptr;

	if (param->l_modifier)
	{
	x = (unsigned long)va_arg(arg, unsigned long);
	}
	else if (param->h_modifier)
	{
	x = (unsigned short int)va_arg(arg, unsigned int);
	}
	else
	{
	x = (unsigned int)va_arg(arg, unsigned int);
	}
	ptr = convert(x, 16, CONVERT_UNSIGNED, param);
	if (param->hashtag_flag && x)
	{
	*--ptr = 'x';
	*--ptr = '0';
	}
	param->unsign = 1;
	return (c += print_num(ptr, param));
}
/**
 * print_octal - print octal
 * @arg: argument
 * @param: parameters struct
 * Return: number
 *
*/
int print_octal(va_list arg, param_t *param)
{
	char *ptr;
	unsigned long x;
	int c = 0;

	if (param->l_modifier)
	{
	x = (unsigned long)va_arg(arg, unsigned long);
	}
	else if (param->h_modifier)
	{
	x = (unsigned short int)va_arg(arg, unsigned int);
	}
	else
	{
	x = (unsigned int)va_arg(arg, unsigned int);
	}
	ptr = convert(x, 8, CONVERT_UNSIGNED, param);
	if (param->hashtag_flag && x)
	{
	*--ptr = '0';
	}
	param->unsign = 1;
	return (c += print_num(ptr, param));
}
