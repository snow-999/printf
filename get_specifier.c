#include "main.h"
/**
 * get_specifier - find the format
 * @s: string
 * Return: number of byts
 *
*/

int (*get_specifier(char *s))(va_list arg, param_t *param)
{
	specifier_t specifier[] =
	{
		{"c", print_char},
		{"d", print_integer},
		{"i", print_integer},
		{"%", print_percent},
		{"s", print_string},
		{"u", print_unsigned},
		{"R", print_rot},
		{NULL, NULL}
	};
	int x = 0;

	while (specifier[x].specifier)
	{
		if (*s == specifier[x].specifier[0])
		{
		return (specifier[x].f);
		}
		x++;
	}
	return (NULL);
}
/**
 * get_print_fun - find the function
 * @s: string
 * @arg: argment
 * @param: parameters struct
 * Return: 0
 *
*/
int get_print_fun(char *s, va_list arg, param_t *param)
{
	int (*f)(va_list, param_t *) = get_specifier(s);

	if (f)
	{
	return (f(arg, param));
	}
	return (0);
}
/**
 * get_flag - find flag
 * @s: string
 * @param: parametrs struct
 * Return: i
*/
int get_flag(char *s, param_t *param)
{
	int i = 0;

	switch (*s)
	{
	case '+':
		i = param->plus_flag = 1;
		break;
	case ' ':
		i = param->space_flag = 1;
		break;
	case '#':
		i = param->hashtag_flag = 1;
		break;
	case '-':
		i = param->minus_flag = 1;
		break;
	case '0':
		i = param->zero_flag = 1;
		break;
	}
	return (i);
}
/**
 * get_modifier - find modifier
 * @s: string
 * @param: parameters struct
 * Return: i
*/
int get_modifier(char *s, param_t *param)
{
	int i = 0;

	switch (*s)
	{
	case 'h':
		i = param->h_modifier = 1;
		break;
	case 'l':
		i = param->l_modifier = 1;
		break;
	}
	return (i);
}
/**
 * get_width - find width
 * @s: string
 * @param: parameters struct
 * @arg: argument
 * Return: s
*/
char *get_width(char *s, param_t *param, va_list arg)
{
	int x = 0;

	if (*s == '*')
	{
	x = va_arg(arg, int);
	s++;
	}
	else
	{
	while (is_digit(*s))
	{
	x = x * 10 + (*s++ - '0');
	}
	}
	param->width = x;
	return (s);
}
