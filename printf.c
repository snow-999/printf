#include "main.h"
/**
 * _printf - print anything
 * @format: format
 * Return: x
*/
int _printf(const char *format, ...)
{
	int x = 0;
	va_list arg;
	char *s , *s1;
	param_t param = PARAM_INT;

	va_start(arg, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
	return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[1])
	{
	return (-1);
	}
	for (s = (char *)format; *s; s++)
	{
	init_param(&param, arg);
	if (*s != '%')
	{
	x = x + _putchar(*s);
	continue;
	}
	s1 = s;
	s++;
	while (get_flag(p, &param))
	{
	s++
	}
	s = get_width(s, &param, arg);
	s = get_precision(s, &param, arg);
	s = get_modifier(s, &param);
	if (get_modifier(s, &param))
	{
	s++;
	}
	if(get_specifier(s))
	{
	x += print_from_to(s1, s,
	param.l_modifier || param.h_modifier ? p - 1 : 0);
	}
	else
	{
	x = x + get_print_fun(s, arg, &param);
	}
	}
	_putchar(BUF_FLUSH);
	va_end(arg);
	return (x);
}
