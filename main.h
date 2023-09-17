#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct specifier: struct token
 * @specifier: format
 * @x: function
 *
*/
typedef struct specifier
{
	char *specifier;
	int (*x)(va_list, param_t);
} specifier_t;

/* string or character */
int _put(char *ptr);
int _putchar(int c);

/* numbers */
/* printf function */
int print_char(va_list arg, param_t *params);
int print_int(va_list arg, param_t *params);
int print_string(va_list arg, param_t *params);
int print_percent(va_list arg, param_t *params);
/*printf prototype*/
int _printf(const char *format, ...);
