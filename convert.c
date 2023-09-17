#include "main.h"
/**
 * convert - convert
 * @num: number
 * @base: base
 * @flag: flag
 * @param: parameter struct
 * Return: str
 *
*/
char *convert(long int num, int base, int flag, param_t *param)
{
	char *arr;
	char buffer[50];
	char sn = 0;
	char *str;
	unsigned long x = num;
	(void)param;

	if (!(flag && CONVERT_UNSIGNED) && num < 0)
	{
		x = -num;
		sn = '-';
	}
	arr = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';
	do {
	*--str = arr[x % base];
	x = x / base;
	} while (x != 0);
	if (sn)
	{
	*--str = sn;
	}
	return (str);
}
/**
 * print_unsigned - print unsigned
 * @arg: argument
 * @param: parameters struct
 * Return: bytes
*/
int print_unsigned(va_list arg, param_t *param)
{
	unsigned long x;

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
	param->unsign = 1;
	return (print_num(convert(x, 10, CONVERT_UNSIGNED, param), param));
}
/**
 * print_adderss - preint address
 * @arg: argument
 * @param: parameters struct
 * Return: bytes
*/
int print_adderss(va_list arg, param_t *param)
{
	unsigned long int num = va_arg(arg, unsigned long int);
	char *ptr;

	if (!num)
	{
	return (_put("(nil)"));
	}
	ptr = convert(num, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, param);
	*--ptr = 'x';
	*--ptr = '0';
	return (print_num(ptr, param));
}
