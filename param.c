#include "main.h"
/**
 * init_param - reset buf
 * @param: parameters struct
 * @arg: argument
 *
*/
void init_param(param_t *param, va_list arg)
{
	param->unsign = 0;
	param->plus_flag = 0;
	param->space_flag = 0;
	param->hashtag_flag = 0;
	param->zero_flag = 0;
	param->minus_flag = 0;
	param->width = 0;
	param->precision  = UINT_MAX;
	param->h_modifier = 0;
	param->l_modifier = 0;
	(void)arg;
}
