#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAM_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 * struct parameters - parameters
 * @unsign: falg
 * @plus_flag: plus flag
 * @zero_flag: zero flag
 * @space_flag: space flag
 * @hashtag_flag: hash flag
 * @minus_flag: munis flag
 * @width: width flag
 * @precision: precision
 * @h_modifier: h_modifier
 * @l_modifier: l_modifier
 *
*/
typedef struct parameter
{
	unsigned int unsign: 1;
	unsigned int space_flag: 1;
	unsigned int minus_flag: 1;
	unsigned int plus_flag: 1;
	unsigned int zero_flag: 1;
	unsigned int hashtag_flag: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier: 1;
	unsigned int l_modifier: 1;
} param_t;
/**
 * specifier - specifier
 * @specifier: format
 * @f: function
 *
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, param_t *);
} specifier_t;

int print_char(va_list arg, param_t *param);
int print_integer(va_list arg, param_t *param);
int print_percent(va_list arg, param_t *param);
int print_S(va_list arg, param_t *param);
char *convert(long int num, int base, int flag, param_t *param);
int print_unsigned(va_list arg, param_t *param);
int print_adderss(va_list arg, param_t *param);
int (*get_specifier(char *s))(va_list arg, param_t *param);
int get_print_fun(char *s, va_list arg, param_t *param);
int get_flag(char *s, param_t *param);
int get_modifier(char *s, param_t *param);
int _printf(const char *format, ...);
int print_rot(va_list arg, param_t *param);
int print_revese(va_list arg, param_t *param);
int print_from_to(char *s, char *t, char *e);
void init_param(param_t *param, va_list arg);
int _putchar(int c);
int _put(char *ptr);
int is_digit(int x);
int length(char *c);
int print_num(char *ptr, param_t *param);
int print_num_right_shift(char *ptr, param_t *param);
int print_num_left_shift(char *ptr, param_t *param);
char *get_precision(char *s, param_t *param, va_list arg);
int _printf(const char *format, ...);
char *get_width(char *s, param_t *param, va_list arg);


#endif /* MAIN_H */
